 inherit ROOM;
void create()
{
        set("short", "����ֱ�");
        set("long", @LONG
�����������������۵ĵط������׵���������������״�ҵ�����������
�����ڽ�����С�����������׵Ľ�ʨ�ھִ���û�ж���һ֧�ڣ�����������ϱ���
��������������Ĵ󲿷ֶ����������У����������Ľ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind3",
  "north" : __DIR__"nwind5",
  "east" : __DIR__"goldlion",
  "west" : __DIR__"stopwin",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/dtz": 2,
                        ]) );
        set("coor/x",0);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
