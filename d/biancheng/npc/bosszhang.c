#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
inherit F_VENDOR; 
void look_for_company(object me, object room, int n);
void summon_npc(object me, object next_room);
int kill_him(); 
void create()
{
        set_name("����ʵ",({"zhang laoshi","zhang","laoshi"}));
        set("title","����ϰ�");
        set("long","����ʵ����Ǹ���ʵ�ˣ�����������С��ݵ��ϰ壬Ҳ�ǳ��Ӻͻ�ƣ�����һ
�굽ͷ����������Χ�ſ��������Χȹ��������һֱæ����ڣ�׬����Ǯȴ��
�����Ŷ������𡣡�\n");
        set("gender","����");
        set("group","citizen"); 
        
        set("combat_exp",4000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                        	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
                "/d/xinjiang/npc/obj/milk",
                "/d/xizang/npc/obj/sheep_leg",
	}));
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_neili",1000+random(500));
        set("neili",query("max_neili"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
                
        set("inquiry", ([
                "����" : "������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
                "ǿ��" : "������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
                "�����ǿ��" : "������������կ����Щɽ��ô��\n",
                "���ڵ�ǿ��" : "����˵������˵ѽ����\n",
                "�����嶾"      :       (: kill_him :),
                   "����"  :               (: kill_him :),
        ]));
        
        
        set("death_msg",CYN"\n$N�ں޵�˵�����ҿ�����ûϣ��Ȣϱ���ˡ���\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
//              10: name()+"�е��������˰���ǿ����ٵ���������\n",
                100: (: look_for_company(this_object(),environment(this_object()),5) :)
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );  */
        set("chat_chance",1);
        set("chat_msg",({
                "����ʵЦ���еص��������棬���档��\n",
                "����ʵ̾�˿���˵���������ӿ���ô����ȥѽ����\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tigerstrike",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}  

void init()
{       

	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
int accept_object(object who, object ob)
{
        if (ob->value()>=300000) {
                if (!who->query_temp("wanma/ʤ��Ʀ")) {
                                command("say �����Ҳû�á��������һ����Ҫ���ߡ�����");
                                command("sigh");
                                return 0;
                } else {
                        command("touch "+who->get_id());
                        command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
                        if (!who->query("wanma/��������ʵ")) {
                                who->set("wanma/��������ʵ",1);
                                who->add("combat_exp",1000);
                           who->add("potential",200);
                                who->add("wanma/����",1);
                                tell_object(who,HIW"�㱻�����ˣ�һǧ��ʵս���飬���ٵ�Ǳ�ܣ�\n"NOR);
                                tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
                        } 
                        return 1;
                }       
        }
        command("shake");
        command("say ����Ĺ����ڰ���");
        return 0;
}  
int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"����ʵ����û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n",this_object());
        another = new(__DIR__"panling");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}   
/*
void look_for_company(object me, object room, int n) { 
        object *inv, next_room;
        int i;  
        mapping exits;
        string *dirs, dest;
        
        
        if( mapp(exits = room->query("exits")) ) 
        {
           dirs=keys(exits);
                for(i=0;i<sizeof(dirs);i++)
                {
                        dest=room->query("exits/"+dirs[i]);
                        if(!next_room=find_object(dest))
                                next_room=load_object(dest);
                        if(!objectp(next_room)) continue;
                        if (next_room==environment(me)) continue;
                        if (next_room->query("summoned")) continue;
                        if(!n) continue;
                        summon_npc(me,next_room);
                        look_for_company(me,next_room,n-1);
                }
        }
        room->delete("summoned");
}  
void summon_npc(object me, object room) {
        object *inv;
        int i;
        
        room->set("summoned",1);
        inv=all_inventory(room);
        if (!sizeof(inv)) return;
        for(i=0;i<sizeof(inv);i++){
                if (inv[i]->is_character() && !userp(inv[i]) 
                        && inv[i]->query("group")==me->query("group")
                        && !inv[i]->is_fighting()) {
                        message_vision("there is a "+inv[i]->query("id")+".\n",me);
                        message_vision("$N˵����"+me->query("name")+"��������ˣ��ҵ�ȥ��������\n",inv[i]);
                        message_vision("$N�Ҵ�ææ���뿪�ˡ�\n",inv[i]);
                        inv[i]->move(environment(me));
                        message_vision("$N����ææ�����˹�����\n",inv[i]);
                }
        }
}  
*/ 
