
void addnl(object who,string typezl,int sl)
{
string msg;
int exp,pot,shen,score,mpgx,gold,kar;
exp=0;
pot=0;
shen=0;
score=0;
mpgx=0;
gold=0;
if (typezl!="mpgx")
{
//if (!who->query("zhuanshen") && !who->query("guard/flag") && !who->query("zhuanbest") && !who->query("4zhuan") && !who->query("5zhuan")) sl=sl*2;
if (who->query("hyvip")==4 || who->query_temp("hyjlexpok",1)==1) sl=sl*2;
}
if (typezl=="exp") exp=sl;
if (typezl=="pot") pot=sl;
if (typezl=="shen") shen=sl;
if (typezl=="score") score=sl;
if (typezl=="mpgx") mpgx=1;
if (typezl=="gold") gold=sl;
if (exp>=3) pot=exp*0.7;

                msg =  "你获得了:";

        if (exp > 0) msg += chinese_number(exp) + "点经验 ";
        if (pot > 0) msg += chinese_number(pot) + "点潜能 ";
        if (shen > 0) msg += chinese_number(shen) + "点正神 ";
        if (shen < 0) msg += chinese_number(-shen) + "点负神 ";
        if (score > 0) msg += chinese_number(score) + "点江湖阅历 ";
        if (mpgx > 0) msg += chinese_number(mpgx) + "点门派功绩 ";
        if (gold > 0) msg += chinese_number(gold) + "两黄金 ";
kar=0;
if (exp >300 && random(3)==0)
{
if (random(2)==0 && who->query("per",1) >20 ) 
{
kar=random((int)who->query("per"))+8;
if (kar>120) kar=120;
msg += chinese_number(kar) + "点额外潜能 ";
        who->add("potential", kar);
}
else if(who->query("kar",1) >20)
{
	
kar=random((int)who->query("kar"))+8;
if (kar>120) kar=120;
msg += chinese_number(kar) + "点额外经验 ";
        who->add("combat_exp", kar);

}
}
        msg += "。\n" ;
        tell_object(who, msg);

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("shen", shen);
        who->add("score", score);
        who->add("mpgx", mpgx);
        who->add("balance", gold*10000);        
}