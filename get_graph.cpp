#include "sierrachart.h"
#include "./src/memoryapi.h"
#include <vector>

SCDLLName("MinuteLogger with Dots")

std::vector<float>* volumeVector = {};

SCSFExport scsf_MinuteLogger(SCStudyInterfaceRef sc) {
    SCInputRef spaceBetweenLines = sc.Input[0];

    if (sc.SetDefaults) {
        sc.GraphName = "Graph Window Overlay";

        sc.GraphRegion = 0;
        sc.AutoLoop = 0;

        spaceBetweenLines.Name = "Odstep";
        spaceBetweenLines.SetInt(30);

        spaceBetweenLines.SetIntLimits(1, 50);
        return;
    }

    if (sc.Index == 0) {
        float cumulativeVolume = 0.0f;
        for (int i = 0; i < sc.ArraySize; i++) {
            if (sc.Close[i] > sc.Open[i]) cumulativeVolume += sc.Volume[i];
            else if (sc.Close[i] < sc.Open[i]) cumulativeVolume -= sc.Volume[i];

            (*volumeVector)[i] = cumulativeVolume;
        }
    } else if (sc.Index > 0) {
        float cumulativeVolume = (*volumeVector)[sc.Index - 1];

        if (sc.GetBarHasClosedStatus(sc.Index - 1) == BHCS_BAR_HAS_CLOSED) {
            if (sc.Close[sc.Index - 1] > sc.Open[sc.Index - 1]) cumulativeVolume += sc.Volume[sc.Index - 1];
            else if (sc.Close[sc.Index - 1] < sc.Open[sc.Index - 1]) cumulativeVolume -= sc.Volume[sc.Index - 1];
        }

        (*volumeVector)[sc.Index] = cumulativeVolume;
    }

      // Assign to main line
    for (int i = 0; i < sc.ArraySize; i++) {
        (*volumeVector)[i] = ((*volumeVector)[i] / 10000000000.0f) + spaceBetweenLines.GetInt();
        //CLB[i] = CumulativeLineTop[i] - spaceBetweenLines.GetInt() * 2;
    }
    
    MemoryMap m;
    m.map(volumeVector);
    
};
