#include <ansi.h>
#include <command.h>
inherit NPC; 
void create()
{ 
        set_name("������",({"long wang","wang"}));
        set("title","����һ��");
        set("long", "������������������ϺƬ���ŵķ��ţ�����һ�����Ĩ���졣��ϲ���������Ϻ��
�����������ݺ��ߺ�ʱ���ɵ�ϰ�ߣ�����ʳ�������������������档��\n");
        set("age",40);
        set("combat_exp", 7000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        set("reward_npc", 1);
        set("difficulty", 3); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
                set_skill("dodge", 380);
set("dex", 180);
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
         set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
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
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
           "�����������ȥ������Ů�����������������Ц�ˡ�\n",
                "��������������ļ�˵����Ů�˵ĺ������������������������������ӣ��������˵ġ���\n",
        }) ); 
        

        setup();
        carry_object(__DIR__"obj/7blade")->wield();
}  
void init()
{
    ::init();   
    add_action("do_look", "look");
}  
int do_look(string arg)
{
    object me,girl;
    me = this_player();
    
    if (girl=present("naked girl",environment(this_object())))
    if( arg == "naked girl" || arg == "girl" )
    {
        message_vision(CYN"$N��������ļ��˵����ô������ɫ�ɲͣ�ʮ���ƽ�������ô�����ô�档\n\n"NOR, this_object());
        return 0;
    }
    else return 0;
} 
int accept_object(object who, object ob)
{
        if( ob->value() >= 100000) {
                        command("spank "+this_player()->get_id());
                        who->set_temp("taiping/longwang_kill",1) ;
                        command("say �ã��������ӻ�����ζ���������͡�\n");
                        return 1;
                } else {
                        command("shake");
                        return 0;
                }
        return 0;
}     
