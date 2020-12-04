 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ǵڶ��߷壬��Ϊ��γ��ַ�⣬���Ա���Ϊ�������������������ƽ
���������󣬹�����������������������������������ˮ���ӣ�����һɫ�������
��Ե�ɺϣ����������￴���ѵ�һ���ķ�⡣
LONG
        );
        set("exits", ([
                "south" : __DIR__"feilai",
                "eastup" : __DIR__"lianhua",
                "southwest" : __DIR__"paiyun",
                "north" : __DIR__"sanhua",
        ])); 
        set("outdoors", "huangshan");
        set("coor/x",-600);
        set("coor/y",-520);
        set("coor/z",30);
         set("objects", ([
//        __DIR__"npc/monkey1" : 1,
                        ]) );  
        setup();
} 
void init() {
        object me;
    int i, dayTime;
    mixed *local;
        add_action("do_jump", "jump");
    me = this_player();

// around 3pm spring or summer afternoon have chance to see foguang
    if ( random(3)==0) {
        return;
    }
    if(query("start_foguang")) {
        return;
    }
    if (!random(10) && random(3)==0) {
        set("start_foguang", 1);
        me->set_temp("foguang", 1);
        remove_call_out("foguang");
        call_out("foguang", random(6) , 0, me);
    }
} 
int valid_leave(object me, string dir){
    if ( me->query_temp("foguang")) {
        me->delete_temp("foguang");
        delete("start_foguang");
    }
    return 1;
} 
void foguang(int stage, object me) {
    object *inv, *watchers;
    int i; 
    remove_call_out("foguang");
        if(!objectp(me) || environment(me) != this_object()) {
            me->delete_temp("foguang");
            delete("start_foguang");
            return;
        }
        if(me->is_fighting()) {
                me->delete_temp("foguang");
                delete("start_foguang");
                return;
        }
    if(stage == 0 && random(30) > 29) {
        message("vision", HIW"     һƬ�Ʋʻ����شӷ嶥Ʈ����\n"NOR, this_object());
    } else  {
        switch(stage) {
        case 0:
            message("vision", HIW"\n         �ƻ���Ʈ�˹�����������ɽ��߻����һƬ�ƺ���\n\n"NOR, this_object());
            message("vision", WHT"�ƺ��ޱ��޼ʣ������÷·�һֱ�������쵽���ϡ�����б�գ���紵��������������\n"NOR, me);
            message("vision", WHT"����ʵ�ĺ���������࣬ȴҲƽ���˼����Իá�\n"NOR, me);
            message("vision", "\n" + me->name() + "�������±߿�ȥ��\n",
                           this_object(),me);
            message("vision", "\n�ƺ��任Ī�⣬�㲻�ɵ��뿿����ϸ������\n", me);
                call_out("foguang", 5, 1, me);
            break;
        case 1:
            message("vision", HIC"\n�ƺ��е���ʲô�������������Ŀ�⣬��Ȼ��һ���˵�Ӱ�ӡ�\n"NOR, me);
            message("vision", HIY"ֻ����Ӱ���𽥵�����������������Χ�γ���һ���޴�Ĳ�ɫ�⻷��\n"NOR, me);
            call_out("foguang", 5, 2, me);
            break;
        case 2:
            message("vision", HIM"\n����ϸ��ʱ��ֻ������ʹ⻷�����Ƽʡ��⻷֮�з������Լ�����Ӱ��\n"NOR, me);
            message("vision", HIM"Ӱ�����ƣ��ֺ����\n"NOR, me);
            message("vision", "\n��ã�����ƺ�����ǰ�ƶ���������\n", me);
            message("vision", "\n" + me->name() + "�����ã�����飬ֱ�����±���ȥ��\n", this_object(),me);
            me->start_busy(4);
            if (!me->query("����B/��ɽ_���") ) {
                call_out("jump", 3, me);
            } else {
                if (random(10) > 5) {
                        call_out("jump", 3, me);
                } else {
                    call_out("wake", 3, me);
                }
            }
            break;
        default:
                        return notify_fail("something wrong\n"); 
        }
    }
}
void wake(object watcher){ 
    message_vision("\nһ��ɽ�紵����$NٿȻ���ѣ��������²���һ��֮ң��$N����һ���亹��\n", watcher);
        watcher->delete_temp("foguang");
        delete("start_foguang");
} 
int jump(object watcher) {
        if (watcher->query("cps") < 10) {
        message("vision", "\n�����ɼ�������������ȥ��\n", watcher);
                message("vision","\n" + watcher->name() + "��ɫһƬ��ã��������������ȥ��\n",
                                this_object(), watcher);
           set("start_foguang", 0);
                watcher->set("����B/��ɽ_���", 1+random(10));
                watcher->start_busy(4);
                if(random(18) > watcher->query("kar")) {
                        call_out("bird", 2, watcher);
                } else {
                        watcher->die();
                }
    } else {
                message("vision", "\nһ��ɽ�紵��������־��΢���ѣ���������һ����һ��֮ң����Զ������ʹ⻷�ƺ�\n", watcher);
                message("vision", "���������������ߡ������ѡ������������������\n", watcher);
                message("vision", "\nһ��ɽ�紵����" + watcher->name() + "��־�����˹�����\n", this_object(), watcher);
                set("start_foguang", 0);
                watcher->set_temp("�������", 1);
        }
    watcher->delete_temp("foguang");
} 
int do_jump() {
        object me; 
        me = this_player(); 
        if(me->query_temp("�������")) {
                me->delete_temp("�������");
                message_vision("$N������������ȥ��\n", me);
                me->set("����B/��ɽ_���", 1+random(10));
                me->start_busy(4);
                call_out("bird", 2, me);
                return 1;
        }
        return 0;
} 
void bird(object me) {
        object room;
        string target;
        int i;
        string *rooms = ({  "/d/huangshan/jiyu",
//                          AREA_XINJIANG"sichou2",
//                          AREA_QUICKSAND"desert3",
//                          AREA_QUICKSAND"quicksand4",
        });
        message("vision", "\n������ʹ⻷��������׹ȥ�������Ǻ����ķ�������ǰһƬ������ʲô����������\n", me);
   message("vision", "��������һƬ�հס�\n", me);
        message("vision", "ͻȻ�䣬���ͷ���������ٵ���ë�Ķ������������ż���ϴ���һ���ʹ��\n", me);
        message("vision", "��е���׹�����ƶ���һ�¡�\n\n", me);
        i=sizeof(rooms);
        target = rooms[random(i)];
        room = find_object(target);
        if(!objectp(room)) {
                room= load_object(target);
    }
    me->move(room);
    me->unconcious();
        message("vision", "\nһֻ��������ӹ���һ�źں����Ķ����ӿ������¡�\n", environment(me),me); 
}   
