// cunzhang.c

inherit ROOM;
void create()
{
        set("short","�ر���");
        set("long",@LONG                                   
�������ͭɽ��ر�Ī��ǫ����ʯΧ��һ��Ժ�������ļ��
�߷����׻�˵�عٲ����ֹܣ���˵�С�Ī��Ǯ��������Ҫ������
�£�ûǮ���治�С�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "south":__DIR__"xiaolu5",
        ]) );

	set("objects",([
	__DIR__"npc/dibao" : 1,
]));

        setup();
        replace_program(ROOM);
}
