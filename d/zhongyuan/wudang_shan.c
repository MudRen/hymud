inherit ROOM;
void create()
{
  set("short","武当山脚");
  set("long",@LONG
武当山地处陕鄂交界处，地势险要，峰峦叠嶂。远远望去，山上遍布青翠的
树林， 绵延起伏，山腰之中隐隐有几处房舍，清澈的溪水自山谷中叮咚而下，
汇成小河，向东流去。
LONG);
  set("exits",([
    "southeast"   : __DIR__"xiaolu2",
  ]));
    set("objects",([
        "/clone/npc/man" : 1,
    ]));
    set("outdoors","zhongyuan");
  setup();
}

