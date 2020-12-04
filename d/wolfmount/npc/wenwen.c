#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({"wenwen"}) );
        set("gender", "����" );
        set("nickname", HIC"������"NOR);
        set("age", 20+random(20));
        set("long",
                "���Ǹ����ŵ��ˣ��ߵú�˹�ģ�̬��Ҳ��˹�ġ�\n");
        set("combat_exp", 100000+random(200000) );
        set("attitude", "friendly");
/*        set("max_jing", 300);
        set("max_qi", 300);
        set("max_jing", 300);  */
        set("fly_target",1);
        set("intellgent",1);
        create_family("��ɽ", 4, "����");
        set("chat_chance", 1);
        set("chat_msg", ({
                "����Ц�����أ���������ش������㡣\n",
//                (: random_move :),
        }));
    set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/zheshan")->wield(); 
        add_money("gold", random(3));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int havenothingon(object ob)
{  
        object *inv;
        inv = all_inventory(ob);
        if (sizeof(inv)==0) 
                return 1;
        else
                return 0;
} 
void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size,temp; 
        if( ob->query("combat_exp")<10000 ) 
                return;
        if( !ob || !visible(ob) || environment(ob) != environment() ) 
                return;
        tar = all_inventory(ob);
        size=sizeof(tar);
        
        if(!havenothingon(ob))
        {
                temp = random(100);
                if ( temp <10 )
                {
                   i=random(size);
                        obj=tar[i];
                        if(!(int)obj->query("no_get") && !(int)obj->query("equipped") && !(int)obj->query("no_drop"))
                        {
                                obj->move(this_object());               
                                tell_object(ob, "���Ȼ����һ��΢����森������������\n");
                                tell_object(ob, "��о�����һ�ᣬ�ƺ�����ʲô����������������\n");
                                message("vision", "�㿴��" + this_object()->name() + "�������ش�" + ob->name() + "����͵����һ" + obj->query("unit") 
                                + obj->name() + "��\n", environment(ob), ({ this_object(), ob }) );
                                return;
                        }
                        else
                        {
                                tell_object(ob, "�����"+this_object()->name()+"�������Ķ����㣮������������\n");
                                tell_object(ob, "��������߾�����С������Ŀ������Լ��Ĺ�����Ʒ��������������\n");
                                return;
                        }
                }
                else if ( temp <80)
                {
                say( "����������ҡ��һ�����ȣ����ŵ�������ȥ��\n");
                        return;
                }
                else
                {
                        say( "����һҾ���أ�����������������Զ�����������ֺ�����\n");
                        return;
                }
        }
        else
        {
                say( "�������ֹ��������������������ɽ�ܣ�\n");
                return;
        }
} 
int accept_fight(object me)
{
        command("say ��ܣ������������Ķ��֣�\n");
        return 0;
}       
