#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;34m����֮��[2;37;0m", ({ "shentong hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;31m�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;31m��֮ͨ����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;31m��Ԫ[2;37;0m [1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [32mˮ[2;37;0m:[1;36m����[2;37;0m [1;35m��[2;37;0m:[1;33m��ʥ[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[1;36m����[2;37;0m 
��ʯ:[34mϸ��[2;37;0m ����:[35m��׼[2;37;0m ����:[31m����[2;37;0m ����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��������[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feige");
		set("ownername", "��������");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",34);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 27);
    set("armor_prop/attack", 32);


    set("armor_prop/armor", 326);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 54);
    set("armor_prop/qi", 62);
    set("armor_prop/jing", 57);
    set("armor_prop/jingli", 57);
    set("armor_prop/damage", 1014);

    set("wtypeA",10);
    set("wtypeB",5);
    set("wtypeC",7);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",13);
    set("wtypeJ",5);
    set("wtypeK",6);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";