#include <ansi.h>
inherit NPC;
inherit __DIR__"timeshift";
inherit F_VENDOR;

int blinding();
int bbqthem(object me, object obj); 
void create()
{ 
        set_name("�ϻ׳�",({"oldworm"}));
        set("long", "
�԰׵�ͷ����������������������׳棬���е����Ǹ�Ϻ�ס���һ���������Ƶ���
������Ȼ��ƣ�룬�ֲ��ϣ�һ˫�۾���ȴ���Ǵ��Ŷ������Ц�⡣\n");
        set("title","�ӻ����ϰ�");
        set("age",60);
        set("combat_exp", 8000000);
        set("reward_npc", 1);
        set("difficulty",15);
                
        set("attitude","friendly");
                
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",30); 
        set("day_room","/d/taiping/zahuo");
        set("shift/day_leave","$N�Ҵ�ææ���뿪�ˡ�\n");
        set("shift/day_arrive","$NЦ�Ǻǵ��߹���˵�����ӻ��̿���ඡ���\n");
        set("night_room","/d/taiping/droad2");
        set("shift/night_leave","$N̽ͷ���˿���ɫ˵����ʱ�䲻�磬����ඡ����漴�������˳�ȥ��\n");
        set("shift/night_arrive","$Nһ����������˹�����\n");
        
        set("dinner_room","/d/taiping/laodian");
        set("shift/dinner_leave","$N���˸����������Է���ʱ�䵽ඡ�����˵��������ȥ��\n");
        set("shift/dinner_arrive","$N�߹����ڰ�����������������\n");
        set("shift/after_dinner","$N���¿��ӣ�������������ȥ��\n");
        set("shift/back_dinner","$N���ű������˹�����\n");
                        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                50:     (: blinding() :),
        ]) );      
        

        
        set_skill("iron-cloth",150);
        

        add_temp("apply/damage",110);
                
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
        setup();
        carry_object(__DIR__"obj/hat2")->wear();
        carry_object(__DIR__"obj/pant")->wear();
        add_money("gold", random(8));
}  
void init() {
        
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("shifting");
                call_out("shifting", 1, me);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void die() {
        
        object me, ob, owner;
        ob=this_object();
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) me = owner;
                
        if(file_name(environment(ob))=="/d/taiping/droad2") me->set("parrot/ɱ�ϻ׳�",1);
        
        ::die();
}
        
int blinding() {
        environment(this_object())->blinding(this_object());
        return 1;
} 
