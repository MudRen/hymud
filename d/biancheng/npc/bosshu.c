#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
inherit NPC;
inherit F_VENDOR; 
int kill_him(); 
void create()
{
        set_name("���ƹ�",({"hu zhanggui","hu","zhanggui"}));
        set("title","����");
        set("long","�����������⣬����һ�Ѵ���ӣ��������̵ĺ��ƹ���Χ��һ���������Χ
ȹ�����ڹ�̨�������⡣���ƹ������ʮ�࣬����ǰ���ڵ����˸����������
ϱ������˵Ů�˿���ȥ�������صģ��½������˺��ӣ����ƹ����������ɹ��
��������᲻�Ƕ���\n");
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",4000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
                "/d/xinjiang/npc/obj/milk",
                "/d/xizang/npc/obj/sheep_leg",
	}));

        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
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
                "ǿ��" : "������ǿ��������Ҳ��ǿ���������ӿ���ô����ȥѽ��\n",
                "�����ǿ��" : "������������կ����Щɽ��ô��\n",
                "���ڵ�ǿ��" : "����˵������˵ѽ����\n",
                "�����嶾"      :               (: kill_him :),
                   "�ɻ���"        :               (: kill_him :),
        ]));
        
        set("death_msg",CYN"\n$N�ں޵�˵������Ӧ����Ӧ������\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                        10: name()+"�е��������˰���ǿ����ٵ���������\n",
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_chance",1);
        set("chat_msg",({
                "���ƹ�˵�����ú���þƣ��þ�����⣬����������Ϻ�����\n",
        }) );                   
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}  
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 

int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"���ƹ�����û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n",this_object());
        another = new(__DIR__"yunzhonghe");
        another->move(environment(this_object()));
        destruct(ob);
        return 1;
}  
void greeting(object ob)
{
        object hu,blade,groom;
        
        if( !ob || environment(ob) != environment() ) return;


        hu=this_object();
        if (ob->query("wanma/����Сϱ��") && !ob->query("wanma/�ͺ��ƹ�")) {
                message_vision("$Ņͷ��$nһ����ˢ��һ�´Ӽ����ϳ��һ�����λε�ɱ����\n",hu,ob);
                if (ob->query("gender")=="Ů��") {
                        command("say Ů�˼Ҳ�ѧ�ã�ȴ����ϱ�����һ�Ǯ�����߿��ߣ�����Ķ����������㡣");
                        groom = find_object("/d/biancheng/road4");
                        if(!objectp(groom)) groom = load_object("/d/biancheng/road4");
                        ob->move(groom);
                        message_vision(HIY "\n$N��$n���˳�����\n"NOR, ob,this_object());
                }
                else {
                        command("say �󵨣����Һ���ϱ��ü����ȥ�Ĺ������ѵ��һ�²��ɣ�");
                        if (!hu->query_temp("weapon")) {
                                blade=new(__DIR__"obj/pblade");
                                blade->move(hu);
                                command("wield blade");
                        }
                        fight_ob(ob);
                        ob->fight_ob(hu);
                        ob->set_temp("wanma/���ƹ�ɱ",1);
                }
        } 
}  
void win_enemy(object loser){
        object groom;
        
        command("puke");
        groom = find_object("/d/biancheng/road4");
        if(!objectp(groom)) groom = load_object("/d/biancheng/road4");
                loser->move(groom);
        message_vision(HIY "\n$N��$n���˳�����\n"NOR, loser,this_object());
}  
void lose_enemy(object winner){
        command("say ��ݣ�������¿�������������ơ�\n");
        winner->delete_temp("wanma/���ƹ�ɱ");
}      
