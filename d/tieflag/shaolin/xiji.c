 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ϰ����");
        set("long", @LONG
���ǵ�������ѧϰ�书���ڣ���ණ���似�������ʴ�ӱ�ĺ󱲵�
���ڴ���������г���򵥣�Ω���м乩��һ������񣬾ݴ�����Ժ�
�����书��ͻ���ͽ����������е������࣬���ݶ��Ǵ���ڤ˼֮�ˡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"damo",
]));
        set("objects", ([
                __DIR__"obj/guanyin" : 1,
       ]) ); 
        set("coor/x",-200);
        set("coor/y",350);
        set("coor/z",70);
        setup();
        replace_program(ROOM); 
}     
