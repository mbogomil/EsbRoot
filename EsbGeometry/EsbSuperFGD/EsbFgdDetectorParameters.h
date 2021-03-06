#ifndef ESBROOT_DATA_SUPERFGD_FGD_DETECTOR_PARAMETERS_H
#define ESBROOT_DATA_SUPERFGD_FGD_DETECTOR_PARAMETERS_H 1

#include "CLHEP/Units/SystemOfUnits.h"
#include "CLHEP/Units/PhysicalConstants.h"

#include "TGeoManager.h"
#include <TGeoBBox.h>
#include <TGeoVolume.h>

#include "TObject.h"

using namespace std;
        
namespace esbroot {

namespace geometry {

namespace superfgd {


namespace DP
{
    static const string  length_X = "length_X";
    static const string  length_Y = "length_Y";
    static const string  length_Z = "length_Z";

    static const string  number_cubes_X = "number_cubes_X";
    static const string  number_cubes_Y = "number_cubes_Y";
    static const string  number_cubes_Z = "number_cubes_Z";

    static const string  visdetail = "visdetail";

    static const string  magField_X = "magField_X";
    static const string  magField_Y = "magField_Y";
    static const string  magField_Z = "magField_Z";

    static const char SEPERATOR='=';
}

class FgdDetectorParameters : public TObject
{
public:
    /** Default constructor **/
    FgdDetectorParameters();

    /** Destructor **/
    ~FgdDetectorParameters();

    /** Read the detector parameters from file
     *@param fullfilePathName - full path of the file
     **/
    void LoadPartParams(string fullfilePathName);

    /** Return the dimentions used for the detector **/
    static Double_t GetLenghtUnit() {return 1.0; /* Default length unit in Root is in 'cm' */}  

    /** Return the existing map parameter as std::string  **/
    string ParamAsString(const string& paramName) const;
    /** Return the existing map parameter as Int_t  **/
    Int_t       ParamAsInt( const string& paramName) const;
    /** Return the existing map parameter as bool  **/
    Bool_t        ParamAsBool(const string& paramName) const;
    /** Return the existing map parameter as Double_t  **/
    Double_t    ParamAsDouble( const string& paramName) const;
    /** Check if parameters exists in the map **/
    Bool_t    ExistsParam(const string& paramName) const;

    /** Return the existing parameters **/
    map<string, string>& GetParamsMap() {return fparamsMap;}
    /** Set the parameter map **/
    void  SetParamsMap(const map<string, string>& newMap){fparamsMap = newMap;}

    FgdDetectorParameters& operator=(FgdDetectorParameters& newDp);

private:

    mutable map<string, string> fparamsMap;

    ClassDef(FgdDetectorParameters,2)
};

}   // superfgd
}   // geometry
}   // esbroot

#endif
