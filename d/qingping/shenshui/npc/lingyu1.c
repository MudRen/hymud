 // XXDER
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("方灵玉" , ({ "lingyu", "girl", "ling yu" }) );
        set("long", "窗边床上端坐着一个女孩，美绝人寰的脸上没有一丝表情，一袭黑纱衬
托着如玉的脸庞，一双眼睛犹如夜空灿烂的星星。她似乎陷入了沉思，
又似乎来聆听海涛声，眼光凝视在窗外的某一点。\n\n");
        set("attitude", "friendly");
        set("inquiry", ([
        "ocean" : "海是神秘的，传说曾经有一族蛟人居住在那里。\n",
        "海" : "海是神秘的，传说曾经有一族蛟人居住在那里。\n",
        ]) );
        set("max_jing", 500);
        set("max_qi", 500);
        set("max_jing", 500);
        set("skill_public",1);
        
        set_skill("parry", 180);

        set_skill("nine-moon-force",180);
                                
        set("age", 14);
        set("gender", "女性" );
        set("per", 30);
        set("combat_exp", 5000);
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();
} 
int answer_react(object me, string arg){
    object mask;
    if(arg == "dunno" && !query("given")) {
        message_vision("\n$N迟疑了一下说道：“海确实是一个神秘的世界，又有谁对那个世界真的了解呢？”\n", me);      
        message_vision("$N微笑着递给$n一样东西同时说道：“也许那一天你会用到这个。”\n", this_object(), me);
        mask = new(__DIR__"obj/jiaoxiao"); set("given",1);
        mask->move(me);    
    } else if(arg == "no"){
        message_vision("$N拍手大笑说道：“那只不过是个哄小孩子的传说罢了。”\n",me);
        message_vision("\n$N微微一笑说道：“是么？”，与此同时$N的手似乎微微一动。\n", this_object());
        tell_object(me, "\n只觉得一阵掌风袭来，你一个旱地拔葱向后闪开，然而脚下一空，你\n");
        tell_object(me, "蓦然一惊，身形已从窗口翻了出去。\n");
        message("vision", "\n" + me->name() + "一个旱地拔葱向后退去，随着一声惊叫身形消失在窗外。\n", 
                environment(me), me);
        environment(me)->fall_out(me); 
    } else if(arg == "yes"){
        message_vision("\n$N道：“我信，沧海月明珠有泪，美丽而多情的蛟人用她们的泪编织海
底世界的神秘瑰丽。”\n", me);
        message_vision("$N注视窗外的双目转了过来看了$n一下，一丝笑容浮现在她脸上，让你不由得
心跳漏掉了一个拍节。\n", this_object(), me);
    }
//    me->delete_temp("marks/lingyu_asked");
    return 1;
} 
void init()
{
    object me;
    ::init();
    if( interactive(me = this_player()) && !is_fighting())
    if (me->query("class")=="shenshui" && me->query("marks/九阴疗伤")) {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
    }
} 
int greeting(object me)
{
    message_vision(CYN"\n$N笑着说，你打败了东海白衣人，真了不起，有空来坐坐，我们聊聊学武心得吧。\n"NOR, this_object(), me);
    return 1;
} 
int recognize_apprentice(object ob)
{
        if(ob->query("class")=="shenshui"&& ob->query("marks/九阴疗伤")) 
                        return 1;
        else return 0;
} 
