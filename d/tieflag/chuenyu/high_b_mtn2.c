 // Room: /d/chuenyu/high_b_mtn2.c
inherit ROOM; 
void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
����ͨ���Ǳ���ʯ�֣�����ʯ��ȫ���þ޴�Ļ��������ɵġ�
������ʯ·�����ѱ����Ǳ����˵ĸ��к����ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"gate_castle",
  "west" : __DIR__"rope_bridge",
]));  
        set("outdoors", "chuenyu"); 
        set("coor/x",130);
        set("coor/y",140);
        set("coor/z",20);
        setup();
}  
