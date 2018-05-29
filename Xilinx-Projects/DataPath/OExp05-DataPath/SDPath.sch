<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1(31:0)" />
        <signal name="XLXN_2(31:0)" />
        <signal name="Data_out(31:0)" />
        <signal name="XLXN_4(4:0)" />
        <signal name="XLXN_5(31:0)" />
        <signal name="MemtoReg" />
        <signal name="RegDst" />
        <signal name="RegWrite" />
        <signal name="ALUSrc_B" />
        <signal name="ALU_Control(2:0)" />
        <signal name="ALU_out(31:0)" />
        <signal name="clk" />
        <signal name="rst" />
        <signal name="XLXN_58" />
        <signal name="Branch" />
        <signal name="PC_out(31:0)" />
        <signal name="XLXN_78(31:0)" />
        <signal name="Jump_addr" />
        <signal name="Branch_offset" />
        <signal name="XLXN_84(31:0)" />
        <signal name="XLXN_85(31:0)" />
        <signal name="XLXN_86" />
        <signal name="Jump" />
        <signal name="XLXN_89(31:0)" />
        <signal name="NO" />
        <signal name="inst_field(25:21)" />
        <signal name="inst_field(20:16)" />
        <signal name="inst_field(15:11)" />
        <signal name="inst_field(25:0)" />
        <signal name="b(31:0)" />
        <signal name="b(2)" />
        <signal name="Data_in(31:0)" />
        <signal name="inst_field(15:0)" />
        <signal name="Ext_out(31:0)" />
        <port polarity="Output" name="Data_out(31:0)" />
        <port polarity="Input" name="MemtoReg" />
        <port polarity="Input" name="RegDst" />
        <port polarity="Input" name="RegWrite" />
        <port polarity="Input" name="ALUSrc_B" />
        <port polarity="Input" name="ALU_Control(2:0)" />
        <port polarity="Output" name="ALU_out(31:0)" />
        <port polarity="Input" name="clk" />
        <port polarity="Input" name="rst" />
        <port polarity="Input" name="Branch" />
        <port polarity="Output" name="PC_out(31:0)" />
        <port polarity="Input" name="Jump" />
        <port polarity="Input" name="inst_field(25:0)" />
        <port polarity="Input" name="Data_in(31:0)" />
        <blockdef name="alu">
            <timestamp>2017-3-28T6:46:32</timestamp>
            <line x2="108" y1="-216" y2="-136" style="linewidth:W;linecolor:rgb(255,0,0)" x1="32" />
            <line x2="108" y1="-72" y2="-136" style="linewidth:W;linecolor:rgb(255,0,0)" x1="32" />
            <line x2="32" y1="-72" y2="96" style="linewidth:W;linecolor:rgb(255,0,0)" x1="32" />
            <line x2="352" y1="-48" y2="-232" style="linewidth:W;linecolor:rgb(255,0,0)" x1="352" />
            <line x2="32" y1="-232" y2="-384" style="linewidth:W;linecolor:rgb(255,0,0)" x1="352" />
            <line x2="32" y1="-216" y2="-384" style="linewidth:W;linecolor:rgb(255,0,0)" x1="32" />
            <line x2="32" y1="-48" y2="96" style="linewidth:W;linecolor:rgb(255,0,0)" x1="352" />
            <line x2="0" y1="-288" y2="-288" style="linewidth:W" x1="32" />
            <line x2="0" y1="16" y2="16" style="linewidth:W" x1="32" />
            <line x2="208" y1="-384" y2="-300" style="linewidth:W" x1="208" />
            <line x2="384" y1="-208" y2="-208" x1="352" />
            <line x2="384" y1="-144" y2="-144" style="linewidth:W" x1="352" />
            <line x2="384" y1="-80" y2="-80" x1="352" />
        </blockdef>
        <blockdef name="Regs">
            <timestamp>2014-6-26T7:27:32</timestamp>
            <rect style="linewidth:W;linecolor:rgb(255,0,0);fillcolor:rgb(254,180,229);fillstyle:Solid" width="352" x="64" y="-448" height="448" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="240" y1="-496" y2="-448" x1="240" />
            <rect width="64" x="416" y="-396" height="24" />
            <line x2="480" y1="-384" y2="-384" x1="416" />
            <line x2="0" y1="-368" y2="-368" x1="64" />
            <rect width="64" x="0" y="-60" height="24" />
            <line x2="0" y1="-48" y2="-48" x1="64" />
            <rect width="64" x="416" y="-124" height="24" />
            <line x2="480" y1="-112" y2="-112" x1="416" />
            <rect width="64" x="0" y="-332" height="24" />
            <line x2="0" y1="-320" y2="-320" x1="64" />
            <rect width="64" x="0" y="-284" height="24" />
            <line x2="0" y1="-272" y2="-272" x1="64" />
            <rect width="64" x="0" y="-204" height="24" />
            <line x2="0" y1="-192" y2="-192" x1="64" />
        </blockdef>
        <blockdef name="MUX2T1_32">
            <timestamp>2015-12-29T3:52:32</timestamp>
            <rect width="40" x="12" y="-100" height="100" />
            <line x2="32" y1="-112" y2="-100" x1="32" />
            <line x2="52" y1="-48" y2="-48" style="linewidth:W;linecolor:rgb(0,0,0)" x1="64" />
            <line x2="0" y1="-80" y2="-80" style="linewidth:W" x1="12" />
            <line x2="0" y1="-16" y2="-16" style="linewidth:W" x1="12" />
        </blockdef>
        <blockdef name="MUX2T1_5">
            <timestamp>2015-12-29T14:47:38</timestamp>
            <line x2="16" y1="-80" y2="-72" x1="16" />
            <line x2="4" y1="-48" y2="-48" style="linewidth:W" x1="0" />
            <line x2="4" y1="-16" y2="-16" style="linewidth:W" x1="0" />
            <line x2="28" y1="-32" y2="-32" style="linewidth:W" x1="32" />
            <rect width="24" x="4" y="-72" height="72" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="REG32">
            <timestamp>2016-1-9T14:9:2</timestamp>
            <rect style="fillcolor:rgb(0,255,255);fillstyle:Solid" width="88" x="32" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="32" />
            <line x2="0" y1="-160" y2="-160" x1="32" />
            <line x2="0" y1="-96" y2="-96" x1="32" />
            <line x2="0" y1="-32" y2="-32" style="linewidth:W" x1="32" />
            <line x2="120" y1="-128" y2="-128" style="linewidth:W" x1="144" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="add_32">
            <timestamp>2015-6-28T14:11:36</timestamp>
            <line x2="16" y1="-48" y2="-48" style="linewidth:W" x1="32" />
            <line x2="16" y1="-16" y2="-16" style="linewidth:W" x1="32" />
            <line x2="96" y1="4" y2="-16" x1="32" />
            <line x2="32" y1="-24" y2="4" x1="32" />
            <line x2="44" y1="-24" y2="-32" x1="32" />
            <line x2="44" y1="-40" y2="-32" x1="32" />
            <line x2="32" y1="-40" y2="-68" x1="32" />
            <line x2="96" y1="-68" y2="-48" x1="32" />
            <line x2="96" y1="-48" y2="-16" x1="96" />
            <line x2="112" y1="-32" y2="-32" style="linewidth:W" x1="96" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <blockdef name="Ext_32">
            <timestamp>2018-5-25T10:15:57</timestamp>
            <circle style="linewidth:W;linecolor:rgb(255,0,0);linestyle:Dash" r="69" cx="185" cy="-33" />
            <line x2="124" y1="0" y2="0" style="linewidth:W" x1="96" />
            <line x2="272" y1="-64" y2="-64" style="linewidth:W" x1="248" />
            <rect style="linecolor:rgb(255,255,255)" width="128" x="120" y="-80" height="88" />
        </blockdef>
        <block symbolname="alu" name="U1_1">
            <blockpin signalname="ALU_Control(2:0)" name="ALU_Ctr(2:0)" />
            <blockpin signalname="ALU_out(31:0)" name="res(31:0)" />
            <blockpin signalname="XLXN_58" name="zero" />
            <blockpin name="overflow" />
            <blockpin signalname="XLXN_1(31:0)" name="A(31:0)" />
            <blockpin signalname="Data_out(31:0)" name="B(31:0)" />
        </block>
        <block symbolname="Regs" name="U2_2">
            <attr value="Regs" name="VeriModel" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="RegWrite" name="L_S" />
            <blockpin signalname="XLXN_1(31:0)" name="rdata_A(31:0)" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="XLXN_5(31:0)" name="Wt_data(31:0)" />
            <blockpin signalname="XLXN_2(31:0)" name="rdata_B(31:0)" />
            <blockpin signalname="inst_field(25:21)" name="R_addr_A(4:0)" />
            <blockpin signalname="inst_field(20:16)" name="R_addr_B(4:0)" />
            <blockpin signalname="XLXN_4(4:0)" name="Wt_addr(4:0)" />
        </block>
        <block symbolname="MUX2T1_32" name="MUXD3">
            <blockpin signalname="ALUSrc_B" name="s" />
            <blockpin signalname="XLXN_2(31:0)" name="I0(31:0)" />
            <blockpin signalname="Ext_out(31:0)" name="I1(31:0)" />
            <blockpin signalname="Data_out(31:0)" name="o(31:0)" />
        </block>
        <block symbolname="MUX2T1_5" name="MUXD1">
            <blockpin signalname="inst_field(15:11)" name="I1(4:0)" />
            <blockpin signalname="inst_field(20:16)" name="I0(4:0)" />
            <blockpin signalname="XLXN_4(4:0)" name="o(4:0)" />
            <blockpin signalname="RegDst" name="s" />
        </block>
        <block symbolname="MUX2T1_32" name="MUXD2">
            <blockpin signalname="MemtoReg" name="s" />
            <blockpin signalname="ALU_out(31:0)" name="I0(31:0)" />
            <blockpin signalname="Data_in(31:0)" name="I1(31:0)" />
            <blockpin signalname="XLXN_5(31:0)" name="o(31:0)" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="XLXN_58" name="I0" />
            <blockpin signalname="Branch" name="I1" />
            <blockpin signalname="XLXN_86" name="O" />
        </block>
        <block symbolname="REG32" name="PC">
            <blockpin signalname="XLXN_89(31:0)" name="D(31:0)" />
            <blockpin signalname="b(2)" name="CE" />
            <blockpin signalname="rst" name="rst" />
            <blockpin signalname="clk" name="clk" />
            <blockpin signalname="PC_out(31:0)" name="Q(31:0)" />
        </block>
        <block symbolname="vcc" name="XLXI_7">
            <blockpin signalname="b(2)" name="P" />
        </block>
        <block symbolname="add_32" name="ADD_PC_4">
            <blockpin signalname="b(31:0)" name="b(31:0)" />
            <blockpin signalname="PC_out(31:0)" name="a(31:0)" />
            <blockpin signalname="XLXN_78(31:0)" name="c(31:0)" />
        </block>
        <block symbolname="add_32" name="ADD_Branch">
            <blockpin signalname="Branch_offset" name="b(31:0)" />
            <blockpin signalname="XLXN_78(31:0)" name="a(31:0)" />
            <blockpin signalname="XLXN_84(31:0)" name="c(31:0)" />
        </block>
        <block symbolname="MUX2T1_32" name="MUXD4">
            <blockpin signalname="XLXN_86" name="s" />
            <blockpin signalname="XLXN_78(31:0)" name="I0(31:0)" />
            <blockpin signalname="XLXN_84(31:0)" name="I1(31:0)" />
            <blockpin signalname="XLXN_85(31:0)" name="o(31:0)" />
        </block>
        <block symbolname="MUX2T1_32" name="MUXD5">
            <blockpin signalname="Jump" name="s" />
            <blockpin signalname="XLXN_85(31:0)" name="I0(31:0)" />
            <blockpin signalname="Jump_addr" name="I1(31:0)" />
            <blockpin signalname="XLXN_89(31:0)" name="o(31:0)" />
        </block>
        <block symbolname="gnd" name="XLXI_15">
            <blockpin signalname="NO" name="G" />
        </block>
        <block symbolname="Ext_32" name="Ext">
            <blockpin signalname="inst_field(15:0)" name="imm_16(15:0)" />
            <blockpin signalname="Ext_out(31:0)" name="Imm_32(31:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2192" y="1680" name="U1_1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="96" type="instance" />
        </instance>
        <instance x="1248" y="1776" name="U2_2" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="32" type="instance" />
        </instance>
        <branch name="XLXN_1(31:0)">
            <wire x2="2192" y1="1392" y2="1392" x1="1728" />
        </branch>
        <instance x="1888" y="1744" name="MUXD3" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <branch name="XLXN_2(31:0)">
            <wire x2="1888" y1="1664" y2="1664" x1="1728" />
        </branch>
        <branch name="Data_out(31:0)">
            <wire x2="2064" y1="1696" y2="1696" x1="1952" />
            <wire x2="2192" y1="1696" y2="1696" x1="2064" />
            <wire x2="2064" y1="1696" y2="1936" x1="2064" />
            <wire x2="3296" y1="1936" y2="1936" x1="2064" />
        </branch>
        <instance x="1104" y="1616" name="MUXD1" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <instance x="1088" y="1776" name="MUXD2" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <branch name="XLXN_4(4:0)">
            <wire x2="1248" y1="1584" y2="1584" x1="1136" />
        </branch>
        <branch name="XLXN_5(31:0)">
            <wire x2="1248" y1="1728" y2="1728" x1="1152" />
        </branch>
        <branch name="MemtoReg">
            <wire x2="1120" y1="1648" y2="1648" x1="192" />
            <wire x2="1120" y1="1648" y2="1664" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="192" y="1648" name="MemtoReg" orien="R180" />
        <branch name="RegDst">
            <wire x2="1120" y1="1392" y2="1392" x1="192" />
            <wire x2="1120" y1="1392" y2="1536" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="192" y="1392" name="RegDst" orien="R180" />
        <branch name="RegWrite">
            <wire x2="1488" y1="1248" y2="1248" x1="192" />
            <wire x2="1488" y1="1248" y2="1280" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="192" y="1248" name="RegWrite" orien="R180" />
        <branch name="ALUSrc_B">
            <wire x2="1920" y1="1200" y2="1200" x1="192" />
            <wire x2="1920" y1="1200" y2="1632" x1="1920" />
        </branch>
        <branch name="ALU_Control(2:0)">
            <wire x2="2400" y1="1136" y2="1136" x1="192" />
            <wire x2="2400" y1="1136" y2="1296" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="192" y="1200" name="ALUSrc_B" orien="R180" />
        <iomarker fontsize="28" x="192" y="1136" name="ALU_Control(2:0)" orien="R180" />
        <branch name="ALU_out(31:0)">
            <wire x2="1088" y1="1696" y2="1696" x1="1008" />
            <wire x2="1008" y1="1696" y2="1840" x1="1008" />
            <wire x2="3072" y1="1840" y2="1840" x1="1008" />
            <wire x2="3072" y1="1536" y2="1536" x1="2576" />
            <wire x2="3280" y1="1536" y2="1536" x1="3072" />
            <wire x2="3072" y1="1536" y2="1840" x1="3072" />
        </branch>
        <iomarker fontsize="28" x="3280" y="1536" name="ALU_out(31:0)" orien="R0" />
        <branch name="clk">
            <wire x2="720" y1="336" y2="336" x1="192" />
            <wire x2="720" y1="336" y2="1360" x1="720" />
            <wire x2="1248" y1="1360" y2="1360" x1="720" />
            <wire x2="848" y1="336" y2="336" x1="720" />
        </branch>
        <branch name="rst">
            <wire x2="704" y1="400" y2="400" x1="192" />
            <wire x2="704" y1="400" y2="1408" x1="704" />
            <wire x2="1248" y1="1408" y2="1408" x1="704" />
            <wire x2="848" y1="400" y2="400" x1="704" />
        </branch>
        <iomarker fontsize="28" x="192" y="336" name="clk" orien="R180" />
        <iomarker fontsize="28" x="192" y="400" name="rst" orien="R180" />
        <iomarker fontsize="28" x="3296" y="1936" name="Data_out(31:0)" orien="R0" />
        <instance x="2704" y="720" name="XLXI_4" orien="R270" />
        <branch name="XLXN_58">
            <wire x2="2640" y1="1472" y2="1472" x1="2576" />
            <wire x2="2640" y1="720" y2="1472" x1="2640" />
        </branch>
        <iomarker fontsize="28" x="192" y="736" name="Branch" orien="R180" />
        <instance x="848" y="560" name="PC" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <instance x="368" y="144" name="XLXI_7" orien="R0" />
        <branch name="PC_out(31:0)">
            <wire x2="1264" y1="432" y2="432" x1="992" />
            <wire x2="1376" y1="432" y2="432" x1="1264" />
            <wire x2="3248" y1="432" y2="432" x1="1376" />
            <wire x2="1376" y1="432" y2="480" x1="1376" />
            <wire x2="1488" y1="480" y2="480" x1="1376" />
        </branch>
        <iomarker fontsize="28" x="3248" y="432" name="PC_out(31:0)" orien="R0" />
        <instance x="1472" y="528" name="ADD_PC_4" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="16" y="4" type="instance" />
        </instance>
        <branch name="Branch">
            <wire x2="2576" y1="736" y2="736" x1="192" />
            <wire x2="2576" y1="720" y2="736" x1="2576" />
        </branch>
        <instance x="2176" y="576" name="MUXD4" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <instance x="2368" y="576" name="MUXD5" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="0" y="0" type="instance" />
        </instance>
        <instance x="1728" y="592" name="ADD_Branch" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="16" y="4" type="instance" />
        </instance>
        <branch name="XLXN_78(31:0)">
            <wire x2="1680" y1="496" y2="496" x1="1584" />
            <wire x2="2176" y1="496" y2="496" x1="1680" />
            <wire x2="1680" y1="496" y2="544" x1="1680" />
            <wire x2="1744" y1="544" y2="544" x1="1680" />
        </branch>
        <branch name="Branch_offset">
            <wire x2="1744" y1="576" y2="576" x1="192" />
        </branch>
        <branch name="Jump_addr">
            <wire x2="2304" y1="640" y2="640" x1="192" />
            <wire x2="2304" y1="560" y2="640" x1="2304" />
            <wire x2="2368" y1="560" y2="560" x1="2304" />
        </branch>
        <branch name="XLXN_84(31:0)">
            <wire x2="2176" y1="560" y2="560" x1="1840" />
        </branch>
        <branch name="XLXN_85(31:0)">
            <wire x2="2304" y1="528" y2="528" x1="2240" />
            <wire x2="2304" y1="496" y2="528" x1="2304" />
            <wire x2="2368" y1="496" y2="496" x1="2304" />
        </branch>
        <branch name="XLXN_86">
            <wire x2="2208" y1="448" y2="464" x1="2208" />
            <wire x2="2608" y1="448" y2="448" x1="2208" />
            <wire x2="2608" y1="448" y2="464" x1="2608" />
        </branch>
        <branch name="Jump">
            <wire x2="2400" y1="272" y2="272" x1="192" />
            <wire x2="2400" y1="272" y2="464" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="192" y="272" name="Jump" orien="R180" />
        <branch name="XLXN_89(31:0)">
            <wire x2="848" y1="528" y2="528" x1="800" />
            <wire x2="800" y1="528" y2="688" x1="800" />
            <wire x2="2496" y1="688" y2="688" x1="800" />
            <wire x2="2496" y1="528" y2="528" x1="2432" />
            <wire x2="2496" y1="528" y2="688" x1="2496" />
        </branch>
        <instance x="2496" y="192" name="XLXI_15" orien="R0" />
        <branch name="NO">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="2608" y="48" type="branch" />
            <wire x2="2560" y1="48" y2="64" x1="2560" />
            <wire x2="2608" y1="48" y2="48" x1="2560" />
        </branch>
        <branch name="inst_field(25:21)">
            <wire x2="672" y1="1456" y2="1456" x1="608" />
            <wire x2="1248" y1="1456" y2="1456" x1="672" />
        </branch>
        <branch name="inst_field(15:11)">
            <wire x2="672" y1="1600" y2="1600" x1="608" />
            <wire x2="912" y1="1600" y2="1600" x1="672" />
            <wire x2="1104" y1="1600" y2="1600" x1="912" />
        </branch>
        <branch name="inst_field(25:0)">
            <wire x2="416" y1="1504" y2="1504" x1="192" />
            <wire x2="512" y1="1504" y2="1504" x1="416" />
            <wire x2="544" y1="1504" y2="1504" x1="512" />
            <wire x2="416" y1="1504" y2="1536" x1="416" />
            <wire x2="416" y1="1536" y2="1600" x1="416" />
            <wire x2="416" y1="1600" y2="1952" x1="416" />
            <wire x2="528" y1="1952" y2="1952" x1="416" />
            <wire x2="512" y1="1600" y2="1600" x1="416" />
            <wire x2="512" y1="1456" y2="1456" x1="416" />
            <wire x2="416" y1="1456" y2="1504" x1="416" />
        </branch>
        <iomarker fontsize="28" x="192" y="1504" name="inst_field(25:0)" orien="R180" />
        <bustap x2="608" y1="1456" y2="1456" x1="512" />
        <bustap x2="640" y1="1504" y2="1504" x1="544" />
        <bustap x2="608" y1="1600" y2="1600" x1="512" />
        <branch name="inst_field(20:16)">
            <wire x2="672" y1="1504" y2="1504" x1="640" />
            <wire x2="688" y1="1504" y2="1504" x1="672" />
            <wire x2="928" y1="1504" y2="1504" x1="688" />
            <wire x2="1248" y1="1504" y2="1504" x1="928" />
            <wire x2="928" y1="1504" y2="1568" x1="928" />
            <wire x2="1104" y1="1568" y2="1568" x1="928" />
        </branch>
        <bustap x2="624" y1="1952" y2="1952" x1="528" />
        <branch name="b(31:0)">
            <wire x2="1376" y1="512" y2="512" x1="1360" />
            <wire x2="1488" y1="512" y2="512" x1="1376" />
        </branch>
        <bustap x2="1264" y1="512" y2="512" x1="1360" />
        <branch name="b(2)">
            <wire x2="432" y1="144" y2="160" x1="432" />
            <wire x2="432" y1="160" y2="464" x1="432" />
            <wire x2="848" y1="464" y2="464" x1="432" />
            <wire x2="1056" y1="160" y2="160" x1="432" />
            <wire x2="1056" y1="160" y2="512" x1="1056" />
            <wire x2="1264" y1="512" y2="512" x1="1056" />
        </branch>
        <branch name="Data_in(31:0)">
            <wire x2="912" y1="1760" y2="1760" x1="224" />
            <wire x2="1088" y1="1760" y2="1760" x1="912" />
        </branch>
        <iomarker fontsize="28" x="224" y="1760" name="Data_in(31:0)" orien="R180" />
        <instance x="1104" y="1952" name="Ext" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial" attrname="InstName" x="96" y="36" type="instance" />
        </instance>
        <branch name="inst_field(15:0)">
            <wire x2="1200" y1="1952" y2="1952" x1="624" />
        </branch>
        <branch name="Ext_out(31:0)">
            <wire x2="1744" y1="1888" y2="1888" x1="1376" />
            <wire x2="1808" y1="1888" y2="1888" x1="1744" />
            <wire x2="1808" y1="1728" y2="1888" x1="1808" />
            <wire x2="1888" y1="1728" y2="1728" x1="1808" />
        </branch>
    </sheet>
</drawing>