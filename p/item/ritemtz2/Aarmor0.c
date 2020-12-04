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
	      set_name("[1;34mÇÇÒÀÎÚË¹Ö®Åû·ç[2;37;0m¡ï", ({ "joeywus armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;34mÔÚÎ÷·½²éÀíÂüÍ³ÖÎµÄÊ±´ú£¬×î¼òÆÓµÄ½£Ò²ÄÜÖµÈıÍ·Ä¸Å£µÄ¼ÛÇ®¡£¶ø²éÀí´óµÛ×Ô¼ºµÄÄÇ°Ñ´«ÆæÊ½
µÄÉñ±ø¡°ÇÇÒÀÎÚË¹¡±¾İËµÊÇ°ëÈË°ëÉñµÄ¡°Î¤À¼Ìú½³¡±ËùÔì£¬ÄËµ±ÊÀ½çÉñ±ø£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÏàµ±¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;37m²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁã½ï°ËÁ½°ËÇ®µÄ[1;34mÇÇÒÀÎÚË¹Ö®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´Ïàµ±¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÌìÔ¨:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÌåÁé:[35m±ê×¼[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",31);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",35);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 47);


    set("armor_prop/armor", 107);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 58);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 21);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";