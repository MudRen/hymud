#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
    set("short", "��������");
    set("long", @LONG
�����ݵصı�Ե����һ��֦Ҷ��ï��С���������Ǳ��̵Ĳݵأ�һ��ƽ���Ĵ�
ʯͷѹ�ڲݵ��ϣ������ɫ��С������ʯͷ���Աߡ�����ʱһ�����С���紵����
������ȫ������һ�������ĺõط���
LONG
        );
        set("long_night", @LONG
���µ��̲ݵ�ϸ�������ڻ谵��ҹ��������Լ���Կ���һ��С����ÿ������
���Ƶ�ҹ����վ������͸��ï�ܵ�֦Ҷ����ɿ��������ǹ⸡����������һ��ƽ
̹�Ĵ�ʯͷ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"lawn",
        ])); 
        set("item_desc", ([
                "stone" : "ƽ̹�Ĵ�ʯͷ������һ����Ȼ�Ĵ󴲣���������¡������������\n",
                "��ʯ" : "ƽ̹�Ĵ�ʯͷ������һ����Ȼ�Ĵ󴲣���������¡������������\n",
        ]) );
    set ("no_magic", 1);
    set("outdoors","taoyuan");
    set("coor/x",240);
    set("coor/y",-50);
    set("coor/z",0);
    setup();
} 
void init(){
        ::init();
        add_action("do_laydown", "laydown");
        add_action("do_getup","getup");
} 
int do_laydown(){ 
        object me, walnut,who;
        int i, j; 
        me = this_player();
   i = NATURE_D->get_season();
        j = random(20); 
        who=query("laydown_person"); 
        if(me==who) return  notify_fail("���Ѿ�������ѽ����\n");
        if(who&&present(who,this_object()))
                return notify_fail("�Ѿ��������ڴ�ʯ���ˡ�����\n"); 
        if(i == 1){
                message("vision", "���紵�������������˯����Ȼ��ʯͷ��Ȼ��Щ��ȴ���������ܡ�\n"
                                , me);
                message("vision", me->name() + "�����ɵ��˴�ʯ�ϡ�\n", this_object(), me);
                set("laydown_person",me);
        } else if(i == 2  ){
                if(NATURE_D->is_day_time()){
                        message("vision", "С����֦Ҷ�����ڵ������⣬�����ʵ��ɵ���ʯ�ϡ�\n", me);
                        message("vision", me->name() + "�����ɵ��˴�ʯ�ϣ������̾��һ�ڳ�����\n",
                                        this_object(), me);
                set("laydown_person",me);
                        if(random(30)<2){
                            remove_call_out("walnut_fall");
                        call_out("walnut_fall", j, me);
                        }
                } else {
                        message("vision", "���õ��ǿ�����ô�����ˣ��㲻����Ȼ������\n", me);
                        if(random(10)<1){
                                remove_call_out("falling_star");
                                call_out("falling_star", j, me);
                        }
                        message("vision", me->name() + "�����ɵ��˴�ʯ�ϡ�\n", this_object(), me);
                        set("laydown_person",me);
                }
        } else if(i == 3){
                message("vision", "�����ˬ����Ҷ���㣬��������������г����˸��ˡ�\n", me);
                message("vision", me->name() + "���������̾��һ�����������г��������Ρ�\n",
                                this_object(), me);
                set("laydown_person",me);
        }
        else if(i == 4){
                message("vision", "������ʯͷ����ٿȻһ��������վ��������\n", me);
                message("vision", "���ɵ�ʯͷ�ϵ�" + me->name() + "���˸���ս��������������\n"
                                , this_object(), me);
   } 
        return 1;
} 
int do_getup()
{
        object me; 
        me=this_player();
        if(me!=query("laydown_person")) return 0;
    remove_call_out("walnut_fall");
        message_vision("$N�Ӵ�ʯ������������\n",me);
        delete("laydown_person");
        return 1;
} 
int valid_leave(object who,string dir)
{
        if(who==query("laydown_person"))
                return notify_fail("���������أ������뿪����\n");
        return ::valid_leave(who,dir);
} 
void walnut_fall(object me)
{
        object walnut; 
        message_vision(RED"�紵������һ����������������ҵ�$N��ͷ�ϡ�\n"NOR, me);
        message_vision(RED"$NٿȻһ����һ��µ����������\n"NOR, me);
        me->set("����B/��Դ_����", 1+random(10));
        walnut = new(__DIR__"obj/walnut");
        walnut->move(this_object());
        delete("laydown_person");
} 
void falling_star(object me)
{
        int age; 
        age = me->query("age");
        message("vision", HIW"ͻȻ֮��һ�����������⻮��ҹ�գ���ʧ���ϱߵ���ʡ�\n"NOR, me);
        if (age >= 10 && age <= 12 && !me->query("����A/��Դ_����")) {
                message("vision", HIG"����������ǰ��ɲ�Ǽ�������һ��Ը������\n"NOR, me);
                message_vision("$NĬĬ��վ��������\n", me);
                me->set("����A/��Դ_����", 1+random(10));
        } else {
        message_vision("$N��ϲ����������������\n", me);
   }
        delete("laydown_person");
}  
