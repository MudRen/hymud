 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ɹ�Ϫ�ߣ������岼��������̶��ƽʱ̶ˮ�峺ƽ����ÿ��΢�紵��������
΢�����������ۣ����Խ���̶������ˮɫ��Ϊ�࣬�࣬�ڣ��ף��ϣ�����һ̶��ˮ
�����������Ա���Ϊ���ء�����ʯ����ʯ����������̣�Ӧ�о��У����з�ζ��
��˵�������µ�����������������̶�����Ҳ��֪��١�
LONG
        );
    set("exits", ([ 
                "east" : __DIR__"sroad",
        "eastup" : "/d/heifeng/lu1",
        ]));
    set("objects", ([
        __DIR__"obj/pond1" : 1,
        __DIR__"obj/pond2" : 1,
        __DIR__"obj/pond3" : 1,
        __DIR__"obj/pond4" : 1,
        __DIR__"obj/pond5" : 1,
        __DIR__"obj/pond6" : 1,
"quest/skills2/wunon/yu/yutan" : 2	,
    ]) );
        set("turtle_home", 1);
    set("outdoors", "huangshan");
        set("coor/x",-660);
        set("coor/y",-540);
        set("coor/z",30);
        setup();
} 
int release_turtle(object turtle) {
        if(turtle->name() != "��ëС�ڹ�") {
                return 0;
        }
        call_out("turtle_return", random(30) + 10, this_player());
        return 1;
} 
void turtle_return(object me) {
        object ob;
        
   if(environment(me) == this_object()) {
                message("vision", "\n\n��ëС�ڹ�������������������Ͼ�Ȼ����һ�����ӡ� \n", this_object());
                message("vision", "��ëС�ڹ�Ѻ����������رߣ�Ȼ��Ǳ��ˮ�ﲻ���ˡ� \n", this_object());
                if(!me->query("m_success/�������")){ 
                me->set("m_success/�������",1); 
                me->add("score",3000); 
                } 
                ob = new(__DIR__"obj/box");
                if(objectp(ob)) {
                        ob->move(this_object());
                }       
        }
}      
