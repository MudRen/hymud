// literate.c

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
  set_name("〖无字经〗", ({"wuzi jing", "jing", "book"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "本");
    set("material", "paper");
    set("unique", 1);
    set("treasure", 1);
    set("value", 0);
    set("long", "一本薄薄的无字经。可以看(kan) \n");
// 这儿的属性严禁修改
// mudring ...
                set("no_steal", "这东西不能丢。\n");
                set("no_drop", "这东西不能丢。\n");
                set("no_put", "珍惜它吧。\n");
                set("no_give", "这东西不能送人。\n");
                set("no_get", "这东西检不起来。\n");

  }
    setup();
}

int query_autoload() { return 1; }
void init ()
{
  object me = this_object();
  object who = this_player();
  add_action ("do_read", "kan");
  add_action ("do_read", "read");
  add_action ("do_read", "study");
  add_action ("do_read", "du");
  add_action ("do_decide", "decide");
        remove_call_out("do_melt");
        call_out("do_melt", 1);

  if (! me->query("my_owner") &&
      interactive (who))
    me->set("my_owner",who->query("id"));
}

void do_melt()
{
        if(this_object()) call_out("melt", 10);
}

void melt()
{
  object me = this_object();
  object who = this_player();
if (!me) return ;

  if (!me->query("my_owner") && me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"这本书是你的么？\n");
    destruct(this_object());
    return;
  }

}
void set_skill (string str)
{
  set("skill", ([
                "name": str,
                "exp_required": 1000000,
                "jing_cost": 25,
                "difficulty": 25,
                "max_skill": 600,
  ]));
}

mapping skills = ([
  "axe": "基本斧法",
  "blade": "基本刀法",
  "dagger": "短兵刃",
  "dodge": "基本轻功",
  "hammer": "基本锤法",
  "parry": "拆招卸力之法",
  "club": "基本棍法",
  "staff": "基本杖法",
  "sword": "基本剑术",
  "throwing": "暗器使用",
  "whip": "基本鞭术",
  "unarmed": "扑击格斗之技",
  "force": "内功心法",
  "literate": "读书识字",
   "taoism": "道学心法",
   "buddhism": "禅宗心法",
   "miaoshouhuichun": "妙手回春",
   "construction": "土木机关",
   "dramaturgy": "梨园旧艺",
   "goplaying": "纹枰手谈",
   "horticulture": "园艺莳花",
"luteplaying": "绕梁琴艺",
"medicine": "济世之术",
"painting": "泼墨丹青",   
]);


 
     
     
     
     
     
     
     


void show_skills ()
{
  int i;
  int size = sizeof (skills);
  string *strs = keys(skills);

  write ("你可以选择如下技能：\n");
  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size; i++)
  {
    write ("  "+strs[i]+": "+skills[strs[i]]+"\n");
  }
}

int do_decide (string arg)
{
  object me = this_object();
  object who = this_player();
  string *strs = keys(skills);
  string str;
  int i;
  int size = sizeof (skills);
 
  if (me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"这本经书不是你的。\n");
    return 1;
  }
  
  if (!who->query("obstacle/reward"))
  {
    tell_object (who,"你没有完成取经任务！"+me->query("obstacle/reward")+"\n");
    return 1;
  }  
  

  if (who->query("obstacle/book"))
  {
    str = skills[who->query("obstacle/book")];
    tell_object (who,"你早已决定用无字经学习"+str+"了。\n");
    return 1;
  }

  for (i = 0; i < size; i++)
  {
    if (arg == strs[i])
    {
      str = skills[arg];
      break;
    }
  }

  if (! str)
  {
    show_skills ();
    return 1;
  }

  who->set("obstacle/book",arg);
  me->set_skill(arg);
  tell_object (who,"你决定从此用无字经学习"+str+"。\n");
  tell_object (who,"你可以将"+str+"学习到六百级。\n");
  who->save();
  return 1;
}

int reading (object me, object book)
{
  mapping skill;
  int cost, my_skill;

  if (environment(me)->query("no_fight") && 
      environment(me)->query("no_magic"))
    return notify_fail("安全区内禁止练功。\n");

  if (!me->query("obstacle/reward"))
return notify_fail("你没有完成取经任务！\n");


                    
  if (me->is_fighting())
    return notify_fail("你无法在战斗中专心下来研读新知！\n");

  if (me->is_busy() || me->query_temp("pending/exercising"))
    return notify_fail("你现在正忙着呢。\n");

  if( !me->query_skill("literate", 1) )
    return notify_fail("你是个文盲，先学学读书识字(literate)吧。\n");

  message_vision ("$N正专心地研读$n。\n",me,book);
  
  skill = book->query("skill");
  my_skill=me->query_skill(skill["name"],1);

  if ((int)me->query("combat_exp") < skill["exp_required"] ||
      ((string)SKILL_D(skill["name"])->type()=="martial"
      && my_skill*my_skill*my_skill/10>(int)me->query("combat_exp")))
  {
    write("你的道行不够，再怎么读也没用。\n");
    return 1;
  }

  notify_fail("以你目前的能力，还没有办法学这个技能。\n");
  if (!SKILL_D(skill["name"])->valid_learn(me))
    return 0;

  cost = skill["jing_cost"] + skill["jing_cost"] 
         * (skill["difficulty"] - (int)me->query_int())/20;
  if ((int)me->query("jing") < cost)
  {
    write("你现在过于疲倦，无法专心下来研读新知。\n");
    return 1;
  }

  if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
  {
    write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
    return 1;
  }

  me->receive_damage("jing", cost);
 if (random(58)==0) me->start_busy(1);
  if (!me->query_skill(skill["name"], 1))
    me->set_skill(skill["name"], 0);
  me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+5);
  write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
  return 1;
}

int do_read (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg ||
      present (arg,who) != me)
    return notify_fail ("你要读什么？\n");

  if (me->query("my_owner") != who->query("id"))
  {
    tell_object (who,"这本经书不是你的。\n");
    return 1;
  }
  if (!who->query("obstacle/reward"))
  {
    tell_object (who,"你没有完成取经任务！\n");
    return 1;
  }  
  
  if (! me->query("skill"))  
  {
    if (who->query("obstacle/book"))
      me->set_skill(who->query("obstacle/book"));
    else
    {
      tell_object (who,"请使用decide来决定你想用经书学习什么。\n");
      return 1;
    }
  }
  return reading (who,me);
}
