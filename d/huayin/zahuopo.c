// zahuopu.c

inherit ROOM;
void create()
{
        set("short","�ӻ���");
        set("long",@LONG                                   
ũ�����ǲ�̫�������ģ�������ӻ���Ҳ������Щũ����
���������˵�С�������ˡ�������˵�ϰ���ǰҲ����Ϊ������ʿ��
��Ҳ������һЩ��ֵ��˹�ˡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu6",
               
        ]) );

	set("objects",([
	__DIR__"npc/seller" : 1,
]));
        setup();
        replace_program(ROOM);
}
