#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","ʯ��");
  set("long",
"ʯ�������˽ǣ����а��ţ��������紵�����㲻�ɵĴ���һ����ս��\n"
"�������ϼ��������ſ�һ̲Ѫ����ǽ����Ҳ�߰ߵ��ɢ����Ѫˮ��������\n"
"��ով���һ�����ҵĲ�ɱ��\n"
);
        set("no_magic", "1");
    set("exits", ([
            "1" : __DIR__"stone1",
            "2" : __DIR__"stone2",
            "3" : __DIR__"stone3",
            "4" : __DIR__"stone4",
            "5" : __DIR__"stone5",
            "6" : __DIR__"stone6",
            "7" : __DIR__"stone7",
 //21              "west" : __DIR__"chukou",
            "8" : __DIR__"stone8",
         "out" :__DIR__"gate",
            "east": __DIR__"lou0",
   ]));
    setup();
}

