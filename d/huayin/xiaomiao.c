// xiaomiao.c

inherit ROOM;
void create()
{
        set("short","С��");
        set("long",@LONG                                   
����ǰ�������Ϲ�����һ�������������Ͼɣ���������
���ѱ����޹���ںڵ���ɫ����������൱�ܵ���ͽ�ľ�����
LONG
        ); 
	set("objects",([
	"/clone/npc/npc" : 1,
]));
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"tulu4",
               
        ]) );

        setup();
        replace_program(ROOM);
}
