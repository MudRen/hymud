// daguchang.c

inherit ROOM;
void create()
{
        set("short","��ȳ�");
        set("long",@LONG                                   
�����Ƿ�԰��ʮ�ɵ�һ��Ƭ�ճ������յ�ʱ���������ũ��
����ɹ����ĵط��������м������˸ߵ���ۣ�������ũ������
һ�����������õġ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu4",
               "east" : __DIR__"xiaolu5",
               "northup":__DIR__"tulu1",
               "south":__DIR__"tulu3",
               
        ]) );
	set("objects",([
	"/clone/npc/man" : 3,
]));

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
