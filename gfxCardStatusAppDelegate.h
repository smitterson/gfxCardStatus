//
//  gfxCardStatusAppDelegate.h
//  gfxCardStatus
//
//  Created by Cody Krieger on 4/22/10.
//  Copyright 2010 Cody Krieger. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Sparkle/Sparkle.h>
#import <Sparkle/SUUpdater.h>
#import <Growl/Growl.h>

@interface gfxCardStatusAppDelegate : NSObject <NSApplicationDelegate,GrowlApplicationBridgeDelegate,NSMenuDelegate> {
	NSWindow *window;
	
	IBOutlet SUUpdater *updater;
	
	NSStatusItem *statusItem;
	
	IBOutlet NSMenu *statusMenu;
	
	// dynamic menu items - these change
	IBOutlet NSMenuItem *versionItem;
	IBOutlet NSMenuItem *currentCard;
	IBOutlet NSMenuItem *currentSwitching;
	IBOutlet NSMenuItem *toggleGPUs;
	IBOutlet NSMenuItem *toggleSwitching;
	IBOutlet NSMenuItem *intelOnly;
	IBOutlet NSMenuItem *nvidiaOnly;
	IBOutlet NSMenuItem *dynamicSwitching;
	
	// process list menu items
	IBOutlet NSMenuItem *processesSeparator;
	IBOutlet NSMenuItem *dependentProcesses;
	IBOutlet NSMenuItem *processList;
	
	// preferences & about window and their controls
	IBOutlet NSWindow *aboutWindow;
	IBOutlet NSWindow *preferencesWindow;
	IBOutlet NSButton *checkForUpdatesOnLaunch;
	IBOutlet NSButton *useGrowl;
	IBOutlet NSButton *logToConsole;
	
	// defaults for all!
	NSUserDefaults *defaults;
	
	// some basic status indicator bools
	BOOL canGrowl;
	BOOL usingIntel;
	BOOL alwaysIntel;
	BOOL alwaysNvidia;
	BOOL usingLate08Or09;
	
	NSString *integratedString;
	NSString *discreteString;
}

- (IBAction)updateStatus:(id)sender;
- (IBAction)openPreferences:(id)sender;
- (IBAction)savePreferences:(id)sender;
- (IBAction)toggleGPU:(id)sender;
- (IBAction)openAbout:(id)sender;
- (IBAction)closeAbout:(id)sender;
- (IBAction)openApplicationURL:(id)sender;
- (IBAction)quit:(id)sender;
- (IBAction)intelOnly:(id)sender;
- (IBAction)nvidiaOnly:(id)sender;
- (IBAction)enableDynamicSwitching:(id)sender;
- (void)setUsingLate08Or09Model:(NSNumber *)value;

+ (bool)canLogToConsole;

@property (assign) IBOutlet NSWindow *window;

@end
