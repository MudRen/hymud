#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "������");
        set("long", @LONG
������һƬ��ֵ����֣���ľ�����Ƿǳ����ܼ����������������͸����ľ
��ҫ������Ȼ����ȴ���Եĸо���һ������Ľӽ���������Ϣ����Ȼ��һ�º�ɫ
���ͱڴ�������ǰ���ּ�û���κο��Ա��ϵĵ�·����о�����ǰ�ľ�����ʱ��
�ض��ڱ仯�ţ����ѷֱ�ʲô����ʲô�ǻá���
LONG
        );
        set("item_desc", ([
                "stone" : (: stone :),
                "ɽʯ" : (: stone :),
        ]));
        set("outdoors","qingping");
        set("coor/x",230);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){ 
    string *rooms = ({"forest1", "forest2", "forest3", "forest4", "forest5", "forest6"});
    string *direction = ({"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"});
        if(this_object()->query("exits")){
                delete("exits");
        }
    set("exits/"+direction[random(8)], __DIR__ + rooms[random(6)]);
        set("exits/"+direction[random(8)], __DIR__+rooms[random(6)]);
        add_action("do_push", "push");
} 
string stone(){
        object me;
        me = this_player();
        if(me->query("class") == "shenshui"){
                tell_object(me, "�ͱ��ϲ����˸�ʽ������ɽʯ������һ��������ơ��������裩\n");
        } else {
                tell_object(me, "�ͱ��ϲ����˸�ʽ������ɽʯ��\n");
   }
        return "";
} 
int valid_leave(object me, string dir){
        object room; 
        if(me->query("class") == "shenshui" && (dir=="north" || dir=="south" || dir=="east" || dir=="west"
                        || dir=="northeast" || dir=="northwest" || dir=="southeast" || dir=="southwest")){
                tell_object(me, "�㲻����ǰ�������Ի������ǰ�С�\n");
                room = find_object(__DIR__"forest5");
                if(!objectp(room)){
                        room = load_object(__DIR__"forest5");
                }
                me->move(room);
                return notify_fail("");
        }
        return 1;
} 
int do_push(string arg){
        object me, room;
        
        me = this_player();
        if(!arg || (arg != "stone" && arg != "ɽʯ")){
                return notify_fail("��Ҫ����ʲô��\n");
        }
        if(me->query("class") == "shenshui"){
                tell_object(me, "��������ɽʯ������һ�ơ�\n");
                tell_object(me, CYN"ɽʯ���ѿ���һ���꣬�������ȥ��ɽʯ����������£��\n\n"NOR);
                message("vision", YEL"����Լ����" + me->name()+"����Ӱ��ʯ����һ������ʧ�����ˡ�\n"NOR, 
                                environment(me), me);
                room = find_object("/d/qingping/shenshui/huoyan");
                if(!objectp(room)){
                        room = load_object("/d/qingping/shenshui/huoyan");
                }
                me->move(room);
        } else {
                tell_object(me, "����������Ҳ���÷���ɽʯ��˿������\n");
        }
        return 1;
} 
