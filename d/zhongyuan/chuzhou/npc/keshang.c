// keshang.c

inherit NPC;


                          
string *first_name = ({
    "张", "李", "田", "赵", "杨", "花", "白", "周", "武", "伍", "戚",
                    });

string *last_name = ({
    "大", "二", "三" ,"四", "五", "六", "七", "八", "九", "十",
                    });                                              
void create()
{
    string name;
    name = first_name[random(sizeof(first_name))];
    name += last_name[random(sizeof(last_name))];
        set_name( name , ({ "ke shang", "trader", "shang" }));
    set("title", "过路客商" );
    set("gender", "男性" );
        set("age", 15+random(50));
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
        set("no_leave_chuzhou", 1);
        set("long",
                "这是一名来往于各大城市之间的客商，身边带了不少货物。\n");
        set("chat_chance", 10);
        set("chat_msg", ({
(: random_move :),
"客商说：“听说前面有强盗？那晚上就在这儿过夜了吧……”\n",
"客商望着周围，想找家便宜的客栈。\n",
 }));
        set("combat_exp", 100000+random(400000));
    set("social_exp", 100000+random(400000));

        set("attitude", "friendly");
        set("no_leave_sizhou", 1);
        setup();
        carry_object( "/clone/misc/cloth" )->wear();

        //carry_object( goods[random(sizeof(goods))]);

        set("possitive_score",100-random(400));
}

int refuse_killing( object who )
{
        object *inv;
        int i;
        message_vision("客商大叫道：“有人抢东西呀！ 快来救命！！”\n", who);
        inv = all_inventory( environment(this_object()) );
        for ( i = 0; i < sizeof(inv); i++ )
        {
                if( inv[i]->query("id") == "ke shang" && inv[i] != this_object() )
                inv[i]->kill_ob(who);
        }
        return 0;
} 

