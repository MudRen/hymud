 inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
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
                "north" : __DIR__"southstrt2",
        ]));
        set("objects", ([
               __DIR__"npc/se" : 1,
        ]) );
        set("indoors", "loulan");
        set("coor/x",-1000);
        set("coor/y",150);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        mapping m_family;
        if( me->query("class") != "knight" )
        {
                if( userp(me) && dir=="north" && ob=present("jiangzuo situ", this_object()) ) 
                {
                        if( !me->query_temp("marks/give_jiangzuo_hehesan"))                
                                return notify_fail("����˾ͽ�ȵ�����վס����ү�ڰ�ϲ���أ�û������͹�һ��ȥ����\n");
                }
        }
        return 1;
}      
