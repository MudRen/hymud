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
                "west" : __DIR__"eaststrt3",
        ]));
        set("objects", ([
               __DIR__"npc/jiu" : 1,
        ]) );
        set("indoors", "loulan"); 
        set("coor/x",-950);
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
                if( userp(me) && dir=="west" && ob=present("han ling", this_object()) ) 
                {
                        if( !me->query_temp("marks/give_han_wine"))                
                                return notify_fail("������ŭ��˵������˭Ҫ�������Ͱ��Ҹ�á���ȸ��������˭�Ϳ��Թ�ȥ����\n");
                }
        }
        return 1;
}    
