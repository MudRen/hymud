#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;31mÉñÍ¨Ö®ÏîÁ´[2;37;0m", ({ "shentong neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
[1;31mÌì±øÉñÍ¨£¬×ßÊÆÒªÆ½ÉÆ£¬ÆøÒªËæĞĞ£¬Á½ÑÛ¹Ë¼â£¬Æø³ÁÁ½×ãÎÈ£¬
Éí·¨Ğè×ÔÈ»£¬ÉíĞĞÈç·ÉÑà£¬ÉíÂäÈçÍ£·ç£¬ÊÕÈç»¨Ğõ£¬´ÌÈç¸Ö¶¤£¡
[2;37;0mÕâÊÇÒ»´®ÓÉÏàµ±¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;37m²ÏË¿[2;37;0mÖÆ³É£¬ÖØÒ»½ïËÄÁ½°ËÇ®µÄ[1;31mÉñÍ¨Ö®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´Ïàµ±¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31mÎŞË«[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÌìĞş:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m 

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
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",34);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 41);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 107);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 63);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",11);
    set("wtypeB",0);
    set("wtypeC",7);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",12);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";