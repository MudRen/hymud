 inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���ȫ���ƹ㳡�����֣�ż���м��ҵ���Ҳ�����˹�ˣ�������²��Ƕ��ƴ�
·����ֱ�������ų��о�Ȼ�������ĵط������ߵ��ż����̳��췢��������������
����������ҹ��ͣ������������һ��˽��ѧ�á����ƺ���û��ʲôѧ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud4",
  "west" : __DIR__"ecloud2",
"north" : __DIR__"smithy",
"south" : __DIR__"washroom",
]));
        set("objects", ([
        __DIR__"npc/wanfan" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",30);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
