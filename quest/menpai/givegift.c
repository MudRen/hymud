
void addnl(object who,string typezl,int sl)
{
string msg;
int exp,pot,shen,score,mpgx,gold;
exp=0;
pot=0;
shen=0;
score=0;
mpgx=0;
gold=0;
if ((int)who->query_temp("teamjobsl",1)>=80) who->set_temp("teamjobsl",80);

if (typezl!="mpgx")
{
if ((int)who->query_temp("teamjobsl",1)>=1) sl=sl+((int)who->query_temp("teamjobsl",1)*50);
if (!who->query("zhuanshen") && !who->query("guard/flag") && !who->query("zhuanbest") && !who->query("4zhuan") && !who->query("5zhuan")) sl=sl+380;
if (who->query("hyvip")==4 || who->query_temp("hyjlexpok",1)==1) sl=sl+380;
}
if (typezl=="exp") exp=sl;
if (typezl=="pot") pot=sl;
if (typezl=="shen") shen=sl;
if (typezl=="score") score=sl;
if (typezl=="mpgx") mpgx=1;
if (typezl=="gold") gold=sl;
if (exp>=10) pot=exp*0.8;

                msg =  "������:";

        if (exp > 0) msg += chinese_number(exp) + "�㾭�� ";
        if (pot > 0) msg += chinese_number(pot) + "��Ǳ�� ";
        if (shen > 0) msg += chinese_number(shen) + "������ ";
        if (shen < 0) msg += chinese_number(-shen) + "�㸺�� ";
        if (score > 0) msg += chinese_number(score) + "�㽭������ ";
        if (mpgx > 0) msg += chinese_number(mpgx) + "�����ɹ��� ";
        if (gold > 0) msg += chinese_number(gold) + "���ƽ� ";

        msg += "��\n" ;
        tell_object(who, msg);
        who->add_temp("teamjobsl",1);
        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("shen", shen);
        who->add("score", score);
        who->add("mpgx", mpgx);
        who->add("balance", gold*10000);        
}