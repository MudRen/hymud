 inherit ROOM;
//inherit NO_FIGHT_ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����Ľ������һ�񣬷����ر�ߣ��ɹ��Σ����滹�и��޴��ʮ�ּܡ�����
�����������ĸ��񡣵����һЩ�𷢱��ۣ���������С��ʹ���������е�ʮ�ּ�
�϶���һ��ȫ����Ѫ���������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind2",
  "north" : __DIR__"chjian",
]));
        set("objects", ([
        __DIR__"npc/priest" : 1,
                        ]) ); 
        //set("throw_exit","west");
        // <- this throw feature does no good to game at all
        // ----------pure silly  
        set("no_fight",1);
        set("no_magic",1);
        set("NONPC",1);
        set("valid_startroom",1);
        set("coor/x",10);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
        //replace_program(NO_FIGHT_ROOM);
} 
