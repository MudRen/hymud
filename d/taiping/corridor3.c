 // seaside.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ·������ˣ�Ժ�ӱ�ֲ������ȴ�ѵ��㣬������ϡ�Σ����������ġ����ֻ
�л��㣬ֻ�г�����Ī˵������Ӱ����������û�У������ĸ��������ƽ�����մ�
�ྶͥ��̧ͷ��ȥ������һ�������εĴ���ɹ�������������������
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"corridor2",
                "west": __DIR__"garden",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        object me,man;
        me=this_player();
        if( userp(me) && me->query("parrot/����ү")==2 && !me->query("parrot/��ү�̿�") ) {
                if (man=present("middle age man",this_object())) return;
                man=new(__DIR__"npc/assassin");
                if (man) {
                        man->move(this_object());
                        message_vision("$N̾��һ��������������һ��Ҫ����������Ҳû�а취����\n",man);
                        man->kill_ob(me);
                        me->kill_ob(man);
                }       
                
        }
}             
