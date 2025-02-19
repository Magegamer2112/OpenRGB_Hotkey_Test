/*-----------------------------------------*\
|  OpenRGBPluginInterface.h                 |
|                                           |
|  OpenRGB Plugin Interface Class           |
|                                           |
|  herosilas12 (CoffeeIsLife)   12/11/2020  |
|  Adam Honse (CalcProgrammer1) 1/5/2021    |
\*-----------------------------------------*/

#pragma once

#include "ResourceManager.h"

#include <QtPlugin>
#include <QLabel>
#include <QMenu>

#define OpenRGBPluginInterface_IID  "com.OpenRGBPluginInterface"

/*-----------------------------------------------------------------------------------------------------*\
| OpenRGB Plugin API Versions                                                                           |
| 0:    OpenRGB 0.6     Unversioned, early plugin API.                                                  |
| 1:    OpenRGB 0.61    First versioned API, introduced with plugin settings changes                    |
| 2:    OpenRGB 0.7     First released versioned API, callback unregister functions in ResourceManager  |
\*-----------------------------------------------------------------------------------------------------*/
#define OPENRGB_PLUGIN_API_VERSION  2

/*-----------------------------------------------------------------------------------------------------*\
| Plugin Tab Location Values                                                                            |
\*-----------------------------------------------------------------------------------------------------*/
enum
{
    OPENRGB_PLUGIN_LOCATION_TOP         = 0,    /* Top-level tab (no icon)                             */
    OPENRGB_PLUGIN_LOCATION_DEVICES     = 1,    /* Devices tab                                         */
    OPENRGB_PLUGIN_LOCATION_INFORMATION = 2,    /* Information tab                                     */
    OPENRGB_PLUGIN_LOCATION_SETTINGS    = 3,    /* Settings tab                                        */
    OPENRGB_PLUGIN_LOCATION_Test = 4,    /* Test tab                                        */
};

struct OpenRGBPluginInfo
{
    /*-------------------------------------------------------------------------------------------------*\
    | Plugin Details                                                                                    |
    \*-------------------------------------------------------------------------------------------------*/    
    std::string                 Name;           /* Plugin name string                                  */
    std::string                 Description;    /* Plugin description string                           */
    std::string                 Version;        /* Plugin version string                               */
    std::string                 Commit;         /* Plugin commit (git or otherwise) string             */
    std::string                 URL;            /* Plugin project URL string                           */
    QImage                      Icon;           /* Icon image (displayed 64x64)                        */

    /*-------------------------------------------------------------------------------------------------*\
    | Plugin Tab Configuration                                                                          |
    \*-------------------------------------------------------------------------------------------------*/
    unsigned int                Location;       /* Plugin tab location from Plugin Tab Location enum   */
                                                /* This field is mandatory, an invalid value will      */
                                                /* prevent plugin tab from being displayed             */
    std::string                 Label;          /* Plugin tab label string                             */
    std::string                 TabIconString;  /* Plugin tab icon string, leave empty to use custom   */
    QImage                      TabIcon;        /* Custom tab icon image (displayed 16x16)             */
};

class OpenRGBPluginInterface
{
public:
    virtual                    ~OpenRGBPluginInterface() {}

    /*-------------------------------------------------------------------------------------------------*\
    | Plugin Information                                                                                |
    \*-------------------------------------------------------------------------------------------------*/
    virtual OpenRGBPluginInfo   GetPluginInfo()                                                     = 0;
    virtual unsigned int        GetPluginAPIVersion()                                               = 0;

    /*-------------------------------------------------------------------------------------------------*\
    | Plugin Functionality                                                                              |
    \*-------------------------------------------------------------------------------------------------*/
    virtual void                Load(bool dark_theme, ResourceManager* resource_manager_ptr)        = 0;
    virtual QWidget*            GetWidget()                                                         = 0;
    virtual QMenu*              GetTrayMenu()                                                       = 0;
    virtual void                Unload()                                                            = 0;
};

Q_DECLARE_INTERFACE(OpenRGBPluginInterface, OpenRGBPluginInterface_IID)
