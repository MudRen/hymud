//jiuguan.c

inherit ROOM;
void create()
{
        set("short","С�ƹ�");
        set("long",@LONG                                   
������ͭɽ��Ψһ��һ��С�ƹݣ�����ũ��վ�ڹ�̨ǰ�ߺ�
�Ÿ����Ʊ�˵��ʲô����һ���ˣ������ƹݾ������������Ƕ���
���Եغ��žƣ�û������˵���ˡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu3",
               
        ]) );

	set("objects",([
	__DIR__"npc/huoji" : 1,
	__DIR__"npc/beg_ma": 1,
]));
        setup();
        replace_program(ROOM);
}
