// datiepu.c

inherit ROOM;
void create()
{
        set("short","������");
        set("long",@LONG                                   
�������ܰ��Ÿ�ʽ��ũ�ߣ�����һ����¯ȼ�š����ڵش���
ɽ���£�������ʿ�������ϣ�Ҳ��һЩ�޲����������顣
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu4",
        ]) );

	set("objects",([
	__DIR__"npc/smith" : 1,
]));
        setup();
        replace_program(ROOM);
}
