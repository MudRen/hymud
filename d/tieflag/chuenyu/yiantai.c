 inherit ROOM;
void create()
{
        set("short", "��̨");
        set("long", @LONG
����һ��СС����̨�������������һֱ����ɽ�š�ǿ��
��ɽ�紵�������ϣ�����е��������ˬ������һ����ȥ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"npc/pigeon" : 2,
        ]) ); 
        set("outdoors", "chuenyu");
        set("coor/x",120);
        set("coor/y",200);
        set("coor/z",50);
        setup();
}    
