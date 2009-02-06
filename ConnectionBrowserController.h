//
//  InternetBrowserController.h
//  SubEthaEdit
//
//  Created by Martin Ott on Wed Mar 03 2004.
//  Copyright (c) 2004-2007 TheCodingMonkeys. All rights reserved.
//           

#import <AppKit/AppKit.h>

#import "LoginSheetController.h"
#import "URLImageView.h"

@class TCMMMBrowserListView, ConnectionBrowserEntry, LoginSheetController,PlainTextDocument;

@interface ConnectionBrowserController : NSWindowController
{
    IBOutlet NSScrollView *O_scrollView;
    IBOutlet TCMMMBrowserListView  *O_browserListView;
    IBOutlet NSImageView *O_imageView;
    IBOutlet NSTextField *O_myNameTextField;
    IBOutlet NSComboBox *O_addressComboBox;
    IBOutlet NSPopUpButton *O_actionPullDownButton;
    IBOutlet NSPopUpButton *O_statusPopUpButton;
    IBOutlet NSButton   *O_toggleFriendcastButton;
    IBOutlet NSButton   *O_clearButton;
    IBOutlet LoginSheetController *O_loginSheetController;

    IBOutlet URLImageView *O_portStatusImageView;
    IBOutlet NSProgressIndicator *O_portStatusProgressIndicator;
    IBOutlet NSTextField *O_portStatusTextField;

    NSMutableArray *I_comboBoxItems;
    NSArrayController *I_entriesController;
    NSMenu *I_contextMenu;
    NSMutableArray *I_storedSelections;
}

+ (ConnectionBrowserController *)sharedInstance;
+ (BOOL)invitePeopleFromPasteboard:(NSPasteboard *)aPasteboard withURL:(NSURL *)aURL;
+ (BOOL)invitePeopleFromPasteboard:(NSPasteboard *)aPasteboard intoDocument:(PlainTextDocument *)aDocument group:(NSString *)aGroup;

- (NSMutableArray *)comboBoxItems;
- (void)setComboBoxItems:(NSMutableArray *)anArray;

- (IBAction)login:(id)aSender;
- (IBAction)connect:(id)aSender;
- (IBAction)setVisibilityByMenuItem:(id)aSender;
- (IBAction)toggleProhibitInboundConnections:(id)aSender;
- (IBAction)toggleFriendcast:(id)aSender;
- (IBAction)clear:(id)aSender;

- (void)connectToAddress:(NSString *)address;

- (void)storeSelection;
- (void)restoreSelection;

@end