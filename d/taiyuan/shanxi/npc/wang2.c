inherit NPC; 
#include <ansi.h>

void create()
{
        set_name("大金鹏王", ({ "peng king" }) );
        set("gender", "男性" );
        set("title",HIG"痴人"NOR);
        set("age", 66);
        set("long", "这些老人脸色都是苍白，显然已有多年未曾见过阳光，身上赫然竟是帝王的打扮。\n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
                set_skill("whip", 20);
        set("chat_chance", 2);
        set("chat_msg", ({
//                (:random_move :),
        "一个老人坐在椅子上痴痴的出神。\n",
        "一个老人正蹲在地上打算盘，嘴里念念有词，仿佛正在计算着这里的财富。\n",
        "一个老人对着面铜镜，正数自己头上的白发。\n",
        }) ); 
        set("inquiry", ([
                "大金鹏王" : "“尔等是何许人？怎敢未经通报，就闯入孤家的寝宫？莫非不知道这是凌迟罪名么？”\n",
                "peng king" : "“尔等是何许人？怎敢未经通报，就闯入孤家的寝宫？莫非不知道这是凌迟罪名么？”\n",
        ]) ); 
        setup();
        add_money("gold", 10);
        carry_object(__DIR__"obj/dcloth")->wear();
        carry_object(__DIR__"obj/yudai")->wield();
        
}       
