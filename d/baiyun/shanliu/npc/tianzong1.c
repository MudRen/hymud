 // acao.c
inherit NPC; 
#include <ansi.h>
void create()
{
        set_name("阿草", ({ "a cao","cao" }) );
        set("gender", "女性" );
        set("age", 21);
        set("title","天宗"+HIG" 柔情刺客"NOR);
        set("long", HIC "\n她长得极美，尤其是那双眼睛，媚得直可以勾人魂魄。\n"+
        "其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。\n"+
        "回眸嫣然一笑，雅如仙子下凡。眼波流转之间，\n"+
        "便把一个少年的心灵，推向梦中极美的境界。\n" NOR);
        set("chat_chance", 5);
        set("chat_msg", ({
            "阿草懒懒一笑道：阿草的刀快？还是阿水的剑快？\n",
            "阿草打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。\n",
            "阿草忽然莞尔一笑道: 阿水待会儿又要我杀谁呢？\n",
            "阿草无聊地绕着手绢，叹道: 唉，一个人，真没意思。\n",
            "阿草伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?\n",
            "阿草斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！\n", 
          }) );
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("per",100);
        set("str", 100);
        set("force",2000);
        set("max_neili",2000);
        set("force_factor",150);
        set_skill("dodge",300);
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
                "阿草幽幽叹道：唉，你这又是何苦呢?\n",
                (: command("say 生有何欢，死亦何忧? 不如就成全了你吧。\n") :),
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
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/blade")->wield();
} 
/*void die()
{
        object ob;
        //command("cry");
        message_vision("\n$N娇喘一口气，说道：阿言会为我报仇的。\n", this_object());
        message_vision("$N说完，化作一缕清风而去。\n", this_object());
        //this_object()->move("/d/fy/church");
        //create();
        destruct(this_object());
}*/
