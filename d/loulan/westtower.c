 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ��Ȼһ�䣬��Ӻڰ��������У������˸��ԻͲ��õ���أ�������
����������һ�޴��ʯ���ϣ����Ż�������׾��ͼ�����ı���ҫ����⡣��ϸ��
ȥ��ԭ���⾹Ȼ������Ρ�������ķ���������ɳĮ���𽥳��ˡ���ʯ��������
����Ҳδ�뵽ɳĮ֮�¾�������û�ΰ��Ľ�����������Ǻ�ʱ�Ի�һʱ��¥
���Ź���ַ��
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"kongquehe",
                "east" : __DIR__"weststrt3",
        ]));
        set("indoors", "loulan");
        set("objects", ([
               __DIR__"npc/cai" : 1,
        ]) ); 
        set("coor/x",-1050);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        mapping m_family;
        if( me->query("class") != "knight" )
        {
                if( userp(me) && dir=="east" && ob=present("jin wuwang", this_object()) ) 
                {
                        if( !me->query_temp("marks/give_jin_gold"))                
                                return notify_fail("������һ�Բ���������΢�������������ǰ��\n");
                }
        }
        return 1;
}     
