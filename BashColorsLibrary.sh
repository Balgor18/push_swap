# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    BashColorsLibrary.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grannou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 08:47:39 by grannou           #+#    #+#              #
#    Updated: 2021/04/15 14:59:23 by grannou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! /bin/bash

# To include this Library:
# . <path to Library>

# 0 = default, 1 = bold/bright, 2 = dim, 4 = underlined, 5 = blink, 7 = reverse, 8 = hidden
# 30 = black, 31 = red, 32 = green, 33 = yellow, 34 = blue, 35 = purple, 36 = cyan, 37 = light gray
# 90 = dark gray, 91 = light red, 92 = light green, 93 = light yellow, 94 = light blue, 95 = light purple, 96 = light cyan, 97 = white

# Reset color
Reset="\033[0m"

# Regular Colors

Black='\033[0;49;30m'        # Black
Red='\033[0;49;31m'          # Red
Green='\033[0;49;32m'        # Green
Yellow='\033[0;49;33m'     # Yellow
Blue='\033[0;49;34m'         # Blue
Purple='\033[0;49;35m'       # Purple
Cyan='\033[0;49;36m'         # Cyan
LGray='\033[0;49;37m'        # LightGray

DGray='\033[0;49;90m'        # DarkGray
LRed='\033[0;49;91m'         # LightRed
LGreen='\033[0;49;90m'       # Light Green
LYellow='\033[0;49;90m'      # Light Yellow
LBlue='\033[0;49;90m'        # Light Blue
LPurple='\033[0;49;90m'      # Light Purple
LCyan='\033[0;49;90m'        # Light Cyan
White='\033[0;49;90m'        # White

# Bold Colors

BBlack='\e[1;49;30m'        # Bold Black
BRed='\033[1;49;31m'          # Bold Red
BGreen='\e[1;32m'        # Bod Green
BYellow='\e[1;33m'       # Bold Yellow
BBlue='\e[1;34m'         # Bold Blue
BPurple='\e[1;35m'       # Bold Purple
BCyan='\e[1;36m'         # Bold Cyan
BLGray='\e[1;37m'        # Bold LightGray

BDGray='\e[1;90m'        # Bold DarkGray
BLRed='\e[1;49;91m'         # Bold LightRed
BLGreen='\e[1;90m'       # Bold Light Green
BLYellow='\e[1;90m'      # Bold Light Yellow
BLBlue='\e[1;90m'        # Bold Light Blue
BLPurple='\e[1;90m'      # Bold Light Purple
BLCyan='\e[1;90m'        # Bold Light Cyan
BWhite='\e[1;90m'        # Bold White

# Dim Colors

DBlack='\e[2;30m'        # Dim Black
DRed='\033[2;49;31m'          # Dim Red
DGreen='\e[2;32m'        # Dim Green
DYellow='\e[2;33m'       # Dim Yellow
DBlue='\e[2;34m'         # Dim Blue
DPurple='\e[2;35m'       # Dim Purple
DCyan='\e[2;36m'         # Dim Cyan
DLGray='\e[2;37m'        # Dim LightGray

DDGray='\e[2;90m'        # Dim DarkGray
DLRed='\e[2;49;91m'         # Dim LightRed
DLGreen='\e[2;90m'       # Dim Light Green
DLYellow='\e[2;90m'      # Dim Light Yellow
DLBlue='\e[2;90m'        # Dim Light Blue
DLPurple='\e[2;90m'      # Dim Light Purple
DLCyan='\e[2;90m'        # Dim Light Cyan
DWhite='\e[2;90m'        # Dim White

# Underlined Colors

UBlack='\e[4;30m'        # Underlined Black
URed='\033[4;49;31m'          # Underlined Red
UGreen='\e[4;32m'        # Underlined Green
UYellow='\e[4;33m'       # Underlined Yellow
UBlue='\e[4;34m'         # Underlined Blue
UPurple='\e[4;35m'       # Underlined Purple
UCyan='\e[4;36m'         # Underlined Cyan
ULGray='\e[4;37m'        # Underlined LightGray

UDGray='\e[4;90m'        # Underlined DarkGray
ULRed='\e[4;49;91m'         # Underlined LightRed
ULGreen='\e[4;90m'       # Underlined Light Green
ULYellow='\e[4;90m'      # Underlined Light Yellow
ULBlue='\e[4;90m'        # Underlined Light Blue
ULPurple='\e[4;90m'      # Underlined Light Purple
ULCyan='\e[4;90m'        # Underlined Light Cyan
UWhite='\e[4;90m'        # Underlined White

# Blink (Clignote) Colors

CBlack='\e[5;4930m'        # Blink Black
CRed='\033[5;49;31m'          # Blink Red
CGreen='\e[5;49;32m'        # Blink Green
CYellow='\e[5;49;33m'       # Blink Yellow
CBlue='\e[5;49;34m'         # Blink Blue
CPurple='\e[5;49;35m'       # Blink Purple
CCyan='\e[5;49;36m'         # Blink Cyan
CLGray='\e[5;49;37m'        # Blink LightGray

CDGray='\e[5;49;90m'        # Blink DarkGray
CLRed='\e[5;49;91m'         # Blink LightRed
CLGreen='\e[5;49;90m'       # Blink Light Green
CLYellow='\e[5;49;90m'      # Blink Light Yellow
CLBlue='\e[5;49;90m'        # Blink Light Blue
CLPurple='\e[5;49;90m'      # Blink Light Purple
CLCyan='\e[5;49;90m'        # Blink Light Cyan
CWhite='\e[5;49;90m'        # Blink White

# Reverse Colors

RBlack='\e[7;30m'        # Reverse Black
RRed='\033[7;49;31m'          # Reverse Red
RGreen='\e[7;32m'        # Reverse Green
RYellow='\e[7;33m'       # Reverse Yellow
RBlue='\e[7;34m'         # Reverse Blue
RPurple='\e[7;35m'       # Reverse Purple
RCyan='\e[7;36m'         # Reverse Cyan
RLGray='\e[7;37m'        # Reverse LightGray

RDGray='\e[7;90m'        # Reverse DarkGray
RLRed='\e[7;91m'         # Reverse LightRed
RLGreen='\e[7;90m'       # Reverse Light Green
RLYellow='\e[7;90m'      # Reverse Light Yellow
RLBlue='\e[7;90m'        # Reverse Light Blue
RLPurple='\e[7;90m'      # Reverse Light Purple
RLCyan='\e[7;90m'        # Reverse Light Cyan
RWhite='\e[7;90m'        # Reverse White

# Hidden Colors

HBlack='\e[8;30m'        # Hidden Black
HRed='\033[8;49;31m'          # Hidden Red
HGreen='\e[8;32m'        # Hidden Green
HYellow='\e[8;33m'       # Hidden Yellow
HBlue='\e[8;34m'         # Hidden Blue
HPurple='\e[8;35m'       # Hidden Purple
HCyan='\e[8;36m'         # Hidden Cyan
HLGray='\e[8;37m'        # Hidden LightGray

HDGray='\e[8;90m'        # Hidden DarkGray
HLRed='\e[8;91m'         # Hidden LightRed
HLGreen='\e[8;90m'       # Hidden Light Green
HLYellow='\e[8;90m'      # Hidden Light Yellow
HLBlue='\e[8;90m'        # Hidden Light Blue
HLPurple='\e[8;90m'      # Hidden Light Purple
HLCyan='\e[8;90m'        # Hidden Light Cyan
HWhite='\e[8;90m'        # Hidden White

# Backgrounds

BlackBg='\e[40m'        # Black
RedBg='\033[1;49;41m'          # Red
GreenBg='\e[42m'        # Green
YellowBg='\e[43m'       # Yellow
BlueBg='\e[44m'         # Blue
PurpleBg='\e[45m'       # Purple
CyanBg='\e[46m'         # Cyan
LGrayBg='\e[47m'        # LightGray

DGrayBg='\e[100m'        # DarkGray
LRedBg='\e[101m'         # LightRed
LGreenBg='\e[102m'       # Light Green
LYellowBg='\e[103m'      # Light Yellow
LBlueBg='\e[104m'        # Light Blue
LPurpleBg='\e[105m'      # Light Purple
LCyanNg='\e[106m'        # Light Cyan
WhiteBg='\e[107m'        # White

# 88/256 colors
# \e[38;5;XXm     0 < XX < 256

# 8ckground 8/256 colors
# \e[48;5;XXm     0 < XX < 256

# Rules \e[style; foreground color; background color m

