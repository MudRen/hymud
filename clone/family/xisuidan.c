// xisuidan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "洗髓丹" NOR, ({ "xisui dan", "dan", "xisuidan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗黑不溜秋的丹药，不知道有什么用。\n");
                set("value", 10000);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
        if (me->query("gift/xisuidan") >= 5 ||
            me->query("gift/con/succeed") >= 5)
        {
                message_vision("$N突然放了一个奇臭无比的响屁。\n", me);
                tell_object(me, "你觉得大概是吃坏了肚子。\n");
        } else
        if (random(5) == 0)
        {
                me->add("gift/con/fail", 1);
                tell_object(me, "不过你觉得好像没什么作用。\n");
        } else
        {
                message("vision", "你似乎听见" + me->name() + "的骨头哗啦啦的响。\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "你浑身的骨骼登时哗啦啦的响个不停，可把你吓坏了，"
                                "好在一会儿就停了下来，似乎筋骨更灵活了。\n" NOR);
                me->add("gift/con/succeed", 1);
                me->add("con", 1);
        }

        if (me->query("gift/xisuidan") < 5)
                me->add("gift/xisuidan", 1);
        destruct(this_object());
        return 1;
}

