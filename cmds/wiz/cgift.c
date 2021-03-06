inherit F_CLEAN_UP;
#include <ansi.h>

int help();

nosave mapping gift_desc = ([
"kar":"福缘",
"per":"容貌",
"str":"膂力",
"con":"根骨",
"dex":"身法",
"int":"悟性"
]);

nosave string *gift = keys(gift_desc);

string check(object me)
{
string msg;

if (me->is_ghost())
msg = HIY"系统提示："NOR"抱歉，你的状态不稳定，现在无法修改属性。\n";
return msg;
}


int main(object me, string arg)
{
string msg, from, to;
int exp, num, newexp, tmpexp;

if (!me) return 0;
if (!arg) return help();

if ( stringp(msg = check(me)) )
return notify_fail(msg);
if (me->query("cgiftok",1)>3)
return notify_fail("玩家只能修改三次天赋!\n");

if (sscanf(arg, "%d %s to %s", num, from, to) == 3){
if (member_array(from, gift) < 0)
return notify_fail("你要扣除什么天赋？\n");
if (member_array(to, gift) < 0)
return notify_fail("你要增加什么天赋？\n");

if (num>20 )
return notify_fail("检查一下，增加属性不能超过20点。\n");

if (from == to || num<0 )
return notify_fail("检查一下，输入错误，可能眼花。\n");
if (me->query(from) <= 10)
return notify_fail("你的"+gift_desc[from]+"不能再减少了。\n");
if ( ((int)me->query(from) - num) < 10)
return notify_fail("你的"+gift_desc[from]+"减少"+num+"点后将少于10点，不能修改。\n");
if (me->query(to) >= 30 )
return notify_fail("你的"+gift_desc[to]+"已经大于30点，不能再增加了。\n");
if ( ((int)me->query(to) + num) > 30)
return notify_fail("你的"+gift_desc[to]+"增加"+num+"点后将超过30点，不能修改。\n");
if ( num > 120 )
return notify_fail("输入的数值超过了你的隐藏属性合。\n");
}
write(HIR"警告如果不想调整属性,从新连接人物取消操作：\n"NOR);
write(HIR"请输入任意键确认：\n"NOR);
input_to("confirm_passwd", me, from, to, num);
return 1;
}

private void confirm_passwd(string pass, object me, string from, string to, int num)
{
me->start_busy(1);

me->add(from, -num);
me->add(to, num);

write("你将"+num+"点"+gift_desc[from]+"调整到"+gift_desc[to]+"上。\n", me);
me->add("cgiftok",1);
me->setup();
me->save();
return;
}

int help()
{
write("本指令用来修改先天属性。\n");
write(HIR"警告如果不想调整属性,从新连接人物取消操作：\n"NOR);
write("比如：你要把一点膂力加到悟性上，你可以用："HIG" cgift 1 str to int "NOR"\n");
write("四项先天属性代号如下:膂力:str,根骨:con,身法:dex,悟性:int,福缘:kar,容貌:per,\n");
write("请慎重使用。\n");
return 1;
}
