#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���幬");
        set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң�������
�ɷ����д�ţ����幬���������֡��ŵ��������һ��ͭʨ��
ʹ�˸е�ׯ�ϵ���������������ط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"grassland2",
]));
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ��������Ż����������(knock)�š�\n",
                "��": "ͭ���Ĵ��ţ��������Ż����������(knock)�š�\n",
        ]) );
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2090);
        set("coor/z",80);
        setup();
} 
void init()
{
//      add_action("do_break", "break");
        add_action("do_knock", "knock");
} 
void wantopen(object me)
{
        object  waiter, tao1, tao2, tao3;
        object  room;  
        seteuid(geteuid());
        room = find_object(__DIR__"da_yuan"); 
        message("vision", "\n֨��һ���������￪�ˡ�\n", this_object());
    if(present("taoist fighter", this_object())){
        return;
    }
        waiter = new(__DIR__"npc/waiter_taoist");
    message("vision", waiter->name()+ "���˹�����\n", this_object());
        if( room )  message("vision", waiter->name() + "֨��һ�����Ŵ򿪣����˳�ȥ��\n", room);
        waiter->move(this_object());
        message("vision", "������˵������λ"+ RANK_D->query_respect(me) + 
                "�����\n", this_object());
        call_out("closedoor", 10, me);
}
/*
void wantbreak(object me)
{
        object  waiter, tao1, tao2, tao3;
        object  room; 
        seteuid(geteuid());
        room = find_object(__DIR__"da_yuan");
        waiter = new(__DIR__"npc/waiter_taoist");
        message("vision", waiter->name()+ "���˹�����\n", this_object());
        waiter->move(this_object());
        message("vision", "\n�����������ȵ�����������"+ RANK_D->query_rude(me) + 
                "���ҵ����幬��Ұ��������������\n", this_object());
        this_object()->set("blocks", ([
                "north" : "fighter",
        ]));
        tao1 = new(__DIR__"npc/up_taoist");
        tao1->move(this_object());
        tao2 = new(__DIR__"npc/reg_taoist");
        tao2->move(this_object());
        tao3 = new(__DIR__"npc/reg_taoist");
        tao3->move(this_object());
        message_vision(HIB "\n�ӵ������ܳ����������ˣ�����û˵�ͺ�$N����������\n\n"NOR, me);
        tao1->kill_ob(me);
        tao2->kill_ob(me);
        tao3->kill_ob(me);
        me->kill_ob(tao1);
        me->kill_ob(tao2);
        me->kill_ob(tao3);
        call_out("closedoor", 20, me);
} 
int do_break(string arg)
{
        object room, me; 
        if( arg=="door" || arg == "��") {
                me = this_player();
                if(query("exits/north")) {
                        message_vision(HIB "$N�ڿ��ŵĴ����ϣ��ݺݵ�����һ�ţ�\n"NOR, me);
                        message_vision(HIB "��һ������̫��ʹ��$Nֱ���죡\n"NOR, me);
                } else if(present("taoist guard", this_object()) || present("taoist fighter", this_object()) 
                                || present("taoist", this_object())){
                        tell_object(me, "�����ڻ��ǲ�Ҫ�����ŵ�Ϊ�á�\n");
                        message("vision", me->name()+"̧����ԥ��һ���ַ���������\n", environment(me), me);
                } else {
                message_vision(HIB "$N����һ�ţ��۵�һ�����Ѵ������˿�����\n"NOR, me);
                set("long", @LONG
ͭ�������ѱ����߿����ŵ��Ϸ�����һ����ң�������
�ɷ����д�ţ����幬���������֡��ŵ��������һ��ͭʨ��
ʹ�˸е�ׯ�ϵ���������������ط���
LONG
        );
                set("exits/north", __DIR__"da_yuan");
                if( room = find_object(__DIR__"da_yuan") ) {
                        message("vision", HIB "�۵�һ�������ű������˿�����\n"NOR, room);
                        room->set("exits/south", __FILE__);
                        room->set("item_desc", ([
                                "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                                "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                        ]) );
                }
                me->start_busy(2);
                call_out("wantbreak", 2, me);
                }
        }
        else {
                 write("��Ҫ��ʲô��\n");
        }
        return 1;
}
*/
int do_knock(string arg)
{
        object room, me, thisroom; 
        if( arg=="door" || arg == "��") {
           me = this_player();
                if(query("exits/north")) {
                        message_vision(HIB "���ǿ��ŵģ���ʲô��\n"NOR, me);
                        return 1;
                }
                message_vision(HIB "$N�ߵ���ǰ����������Ż��������¡�\n"NOR, me);
                set("long", @LONG
ͭ�����ų����ţ��ŵ��Ϸ�����һ����ң��������ɷ�
���д�ţ����幬���������֡��ŵ��������һ��ͭʨ��ʹ
�˸е�ׯ�ϵ���������������ط���
LONG
        );
                set("exits/north", __DIR__"da_yuan");
                if( room = find_object(__DIR__"da_yuan") ) {
                        message("vision", HIB "�����������������������������š�\n"NOR, room);
                        room->set("exits/south", __FILE__);
                        room->set("item_desc", ([
                                "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                                "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                        ]) );
                }
                me->start_busy(2);
                call_out("wantopen", 2, me);
                
        }
        else {
                write("��Ҫ��ʲô��\n");
        }
                return 1;
} 
void closedoor(object me)
{
        object obj, room, troom; 
        troom = this_object();
        if(environment(me) != troom) {
                room = find_object(__DIR__"da_yuan");
                obj = present("guard", troom);
                if(obj) {
                        message("vision",obj->name() + "�߽��˵��ۡ�\n", troom);
                        destruct(obj);
           }
                obj = present("taoist", troom);
                if(obj) {
                        message("vision", obj->name() + "�߽��˵��ۡ�\n", troom);
                        destruct(obj);
                }
                obj = present("taoist", troom);
                if(obj) {
                        message("vision", obj->name() + "�߽��˵��ۡ�\n", troom);
                        destruct(obj);
                }
                obj = present("fighter", troom);
                if(obj) {
                        message("vision", obj->name() + "�߽����ۣ�����ذ��Ź����ˡ�\n", troom);
                        destruct(obj); 
                        }
                        if(room) {
                                room->delete("exits/south");
                                room->set("item_desc", ([
                        "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                        "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                                ]) );
                        delete("exits/north");
                        
        set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң�������
�ɷ����д�ţ����幬���������֡��ŵ��������һ��ͭʨ��
ʹ�˸е�ׯ�ϵ���������������ط���
LONG
        );
                }
        } else {
                call_out("closedoor", 15, me);
        }
}  
void reset(){
        object room;
        ::reset();
        if(query("exits/north")){
                set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң�������
�ɷ����д�ţ����幬���������֡��ŵ��������һ��ͭʨ��
ʹ�˸е�ׯ�ϵ���������������ط���
LONG
                );      
                room = find_object(__DIR__"da_yuan");
                if(objectp(room) && room->query("exits/south")){
                        room->delete("exits/south");
                }
                delete("exits/north");
        }
}       
