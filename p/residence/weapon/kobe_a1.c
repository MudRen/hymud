#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;31mÉñÍ¨Ö®·ş×°[2;37;0m", ({ "shentong cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;31mÌì±øÉñÍ¨£¬×ßÊÆÒªÆ½ÉÆ£¬ÆøÒªËæĞĞ£¬Á½ÑÛ¹Ë¼â£¬Æø³ÁÁ½×ãÎÈ£¬
Éí·¨Ğè×ÔÈ»£¬ÉíĞĞÈç·ÉÑà£¬ÉíÂäÈçÍ£·ç£¬ÊÕÈç»¨Ğõ£¬´ÌÈç¸Ö¶¤£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¾Å½ïÁãÁ½¶şÇ®µÄ[1;31mÉñÍ¨Ö®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [32mË®[2;37;0m:[1;31m´´ÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÌìÔ¨:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ×ÏÊ¯:[1;36mÍêÃÀ[2;37;0m ÖÜÌì:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿Æ±È[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m°µÆ÷[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "¿Æ±È");
		set("value", 25000);
		set("armor_prop/intelligence",32);
		set("armor_prop/strength",0);
		set("armor_prop/karey",40);
		set("armor_prop/percao",25);
		set("armor_prop/dexerity",34);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 66);
    set("armor_prop/parry", 73);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 1039);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 73);
    set("armor_prop/qi", 37);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 251);

    set("wtypeA",8);
    set("wtypeB",7);
    set("wtypeC",14);
    set("wtypeD",14);
    set("wtypeE",5);
    set("wtypeF",4);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",5);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";