 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǰ��Ψ��˫�ֹ������Ա���С��ͷ�ĳߴ磬������ڸߵͲ�ƽ
��ɽ��֮�ϣ�һ·�ƽ���������խ�Ķ�Ѩ֮�У�һ��һ�����ǰ��ȥ������
�������˱㲻�ٱ�խ��
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"tunnel3",
                "down" : __DIR__"tunnel1",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object who,string dir)
{
        if(userp(who) && random(5))        {
                who->move(this_object());
                return notify_fail("");
        }
        return 1;
}   
