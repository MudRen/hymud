inherit ITEM;

void create()
{
        set_name("蹁跹步法秘籍", ({ "dodgebook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long",
"这本书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
"写的是男女之间的一些情话什么得。\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "dodge", // 武功名称
        "exp_required": 1000,    // 读此书需要的最低经验.
        "jing_cost":     50,      // 读书花的神.
        "difficulty":   25,      // 参看 /cmds/std/study.c
        "max_skill":    181,      // 能读到的最高等级.
]) );
        }
}
int is_jinghai_book() { return 1; }

