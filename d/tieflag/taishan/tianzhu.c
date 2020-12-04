 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","天柱峰");
  set("long",@LONG
这是泰山的主峰，也是最高峰，峰上建有玉皇观一座，日观亭，望
河亭，古登封台四周环绕，历代帝王便是在这里祭天酬神，在此“旭日
东升”，“晚霞夕照”，“黄河金带”，“云海玉盘”四大奇景尽收眼
底。
LONG
  );
  set("exits",([
        "southdown" : __DIR__"bixia",
               ]));
        set("outdoors", "taishanfy");
        set("objects", ([
       ]) );
        set("coor/x",330);
        set("coor/y",2400);
        set("coor/z",130);
        setup();
        replace_program(ROOM);
}       
