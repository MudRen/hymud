 inherit ROOM;
void create()
{
        set("short", "����·��");
        set("long", @LONG
���������Һ��ģ��е��޻���������Ҳ��С���Ľ�����������ƺ���ææµ
µ�ģ��������ֲ�֪��æЩʲô���ϲ���һ����ˮ�أ�ˮɫī�̣�ɢ���ŵ�������
�̡���ɫ���룬�����һ�ж��������ƺ������ڵ����С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud5",
  "west" : __DIR__"ecloud3",
"north" : __DIR__"mianhua",
"south" : __DIR__"ponder",
]));
        set("objects", ([
        __DIR__"npc/drugseller" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",40);
        set("coor/y",0);
        set("coor/z",0);
        set("coor/x",40);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
