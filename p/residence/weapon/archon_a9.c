#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;36m���֮����[2;37;0m", ({ "tiandi armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;36m���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;36m���֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m����[2;37;0m [32mˮ[2;37;0m:[1;34m����[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[31m����[2;37;0m 
����:[1;36m����[2;37;0m ��ʯ:[1;36m����[2;37;0m ����:[31m����[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32mצ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "����");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",40);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 72);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 412);
    set("armor_prop/defense", 71);
    
    set("armor_prop/neili", 69);
    set("armor_prop/qi", 47);
    set("armor_prop/jing", 52);
    set("armor_prop/jingli", 52);
    set("armor_prop/damage", 82);

    set("wtypeA",14);
    set("wtypeB",6);
    set("wtypeC",8);
    set("wtypeD",5);
    set("wtypeE",11);
    set("wtypeF",13);
    set("wtypeG",6);
    set("wtypeH",3);
    set("wtypeI",4);
    set("wtypeJ",5);
    set("wtypeK",4);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";