 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object ob,con;
        set("short", "����¥");
        set("long", @LONG
һ��ͤ���ƵĽ������м�һ��ţƤ�޹ģ��ഫ��ӡ����ţƤ�Ƴɣ�
����ɮ�����ڹ��ԣ���ʱ���ģ�һ�㶼��ĺ�ĳ��ӣ�����ʱ��������
����������Ĺ�����
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"gulou3",
]));
        set("objects", ([
                __DIR__"npc/monk5" : 3,
       ]) );
        set("coor/x",-220);
        set("coor/y",200);
        set("coor/z",70);
        set("outdoors","shaolin");
        setup();
        con = new(__DIR__"obj/gu");
        con->move(this_object());
}       
