 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ǳ�͢���裬���Ƴ���ľ��׶�������������״��������������һ�ž�
��ľ���������и�С��Ͱ��������ż�����֪����ӡ����ǩ��ľ�����̫ʦ��������
ѩ��Ƥ���κ������Ϻ�������ͼ����������ң�
                                �������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
  "east" : __DIR__"shufang",
]));
        set("objects", ([
        __DIR__"npc/yayi1" : 3,
        __DIR__"npc/yayi" : 3,
        __DIR__"npc/yayi2" : 3, 
                        ]) );
        set("NONPC",1);
        set("coor/x",-21);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
