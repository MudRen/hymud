 // Room: /d/shaolin/shandao3.c
inherit ROOM; 
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ����ֱ��ɽ·���Ϸ����죬һֱ��û������֮�У�ɽ
����������һƬ�����֣�С����������ͷ紵�����ֵ�ɳɳ����
֯�������Ĵ���Ȼ�����ɡ������Ƕ��͵�ɽ�¡�·�Ͼ����ܿ���
����ɮ����������������һֱ�߾����������������ˡ�
LONG
        ); 
        set("outdoors", "shaolin"); 
        set("exits", ([ /* sizeof() == 3 */
        "northup" : __DIR__"shandao2",
        "west" : __DIR__"zhulin/entry",
        "southdown" : __DIR__"shandao4",
])); 
        setup();
        replace_program(ROOM);
}     
